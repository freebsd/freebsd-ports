# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	enma
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/ENMA/${PORTVERSION}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Sender authentication milter supporting SPF and Sender ID

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	LIBBIND
LIBBIND_DESC=	Link against dns/libbind instead of dns/ldns

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/man \
			--with-ssl-incdir=${OPENSSLINC} --with-ssl-libdir=${OPENSSLLIB}

USES=		gmake perl5
USE_RC_SUBR=	milter-enma
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_PERL5=	build
MANLANG=	"" ja_JP.UTF-8
MAN1=		enma.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/sidfquery etc/enma.conf.sample lib/libsauth.a lib/libsauth.la \
		lib/libsauth.so lib/libsauth.so.0 libexec/enma
PORTDOCS=	ChangeLog INSTALL LICENSE README
SUB_FILES=	milter-enma

.if defined(WITH_POSTFIX_MILTER) || defined(WITH_POSTFIX) || defined(WITH_POSTFIX_CURRENT)
CONF_SUB=	${REINPLACE_CMD} -e '/milter\.postfix/s/false/true/' ${WRKSRC}/enma/etc/enma.conf.sample
. if defined(WITH_POSTFIX_CURRENT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix-current
. else
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
. endif
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if ${PORT_OPTIONS:MLIBBIND}
CONFIGURE_ARGS+=	--with-resolver=libbind \
			--with-libbind-incdir=${LOCALBASE}/include/bind \
			--with-libbind-libdir=${LOCALBASE}/lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libbind.a:${PORTSDIR}/dns/libbind
.else
CONFIGURE_ARGS+=	--with-resolver=ldns
LIB_DEPENDS+=	ldns:${PORTSDIR}/dns/ldns
.endif

pre-configure:
	$$(${CONF_SUB})

post-install:
	${INSTALL_DATA} ${WRKSRC}/enma/etc/enma.conf.sample ${PREFIX}/etc
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD} "@unexec ${RMDIR} %D/man/ja_JP.UTF-8/man1 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/man/ja_JP.UTF-8 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>

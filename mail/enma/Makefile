PORTNAME=	enma
PORTVERSION=	1.2.0
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/ENMA/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sender authentication milter supporting SPF and Sender ID
WWW=		https://sourceforge.net/projects/enma/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-ssl-incdir=${OPENSSLINC} \
		--with-ssl-libdir=${OPENSSLLIB}

USES=		gmake libtool perl5 ssl
BROKEN_SSL=	openssl openssl31
BROKEN_SSL_REASON=	Fails to build with error undefined reference due to --no-allow-shlib-undefined: EVP
USE_RC_SUBR=	milter-enma
USE_LDCONFIG=	yes
USE_PERL5=	build
LDFLAGS+=	-lssl
MANLANG=	"" ja_JP.UTF-8
PORTDOCS=	ChangeLog INSTALL LICENSE README
SUB_FILES=	milter-enma

OPTIONS_DEFINE=	DOCS LIBBIND

LIBBIND_DESC=	Link against dns/libbind instead of dns/ldns

LIBBIND_CONFIGURE_ON=	--with-resolver=libbind \
			--with-libbind-incdir=${LOCALBASE}/include/bind \
			--with-libbind-libdir=${LOCALBASE}/lib
LIBBIND_BUILD_DEPENDS=	${LOCALBASE}/lib/libbind.a:dns/libbind
LIBBIND_CONFIGURE_OFF=	--with-resolver=ldns
LIBBIND_LIB_DEPENDS_OFF=	libldns.so:dns/ldns

.if defined(WITH_POSTFIX_MILTER) || defined(WITH_POSTFIX) || defined(WITH_POSTFIX_CURRENT)
CONF_SUB=	${REINPLACE_CMD} -e '/milter\.postfix/s/false/true/' ${WRKSRC}/enma/etc/enma.conf.sample
. if defined(WITH_POSTFIX_CURRENT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:mail/postfix-current
. else
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:mail/postfix
. endif
.endif

.include <bsd.port.options.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

pre-configure:
	$$(${CONF_SUB})

post-install:
	${INSTALL_DATA} ${WRKSRC}/enma/etc/enma.conf.sample \
		${STAGEDIR}${PREFIX}/etc
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.  endfor
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sidfquery \
		${STAGEDIR}${PREFIX}/lib/libsauth.so \
		${STAGEDIR}${PREFIX}/libexec/enma

.include <bsd.port.post.mk>

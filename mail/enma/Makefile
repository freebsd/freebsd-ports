# New ports collection makefile for:	enma
# Date created:				7 Sep 2008
# Whom:					Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	enma
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/ENMA/${PORTVERSION}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A sender authentication milter supporting SPF and Sender ID

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/dns/bind97:checksum

.if defined(WITH_POSTFIX_MILTER) || defined(WITH_POSTFIX) || defined(WITH_POSTFIX_CURRENT)
CONF_SUB=	${REINPLACE_CMD} -e '/milter\.postfix/s/false/true/' ${WRKSRC}/enma/etc/enma.conf.sample
.if defined(WITH_POSTFIX_CURRENT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix-current
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
.endif
.endif

BIND_PATH_CMD=	cd ${PORTSDIR}/dns/bind97 && ${MAKE} -V WRKSRC
BIND_SRC_DIR=	${BASENAME} $$(${BIND_PATH_CMD})

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/man \
			--with-libbind=${WRKSRC}/build/tmp_build
USE_RC_SUBR=	milter-enma
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE
MANLANG=	"" ja_JP.UTF-8
MAN1=		enma.1
MANCOMPRESSED=	no
PLIST_FILES=	libexec/enma bin/sidfquery etc/enma.conf.sample
PORTDOCS=	ChangeLog INSTALL LICENSE README TODO
SUB_FILES=	milter-enma

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

USE_OPENSSL=	yes
.if ${OSVERSION} < 700000
WITH_OPENSSL_PORT=	yes
.endif
.include "${PORTSDIR}/Mk/bsd.openssl.mk"

pre-configure:
	cd ${PORTSDIR}/dns/bind97 && ${MAKE} -DBATCH patch && \
	${LN} -s $$(${BIND_PATH_CMD}) ${WRKSRC}/build && \
	cd ${WRKSRC}/build/$$(${BIND_SRC_DIR}) && \
	./configure --prefix=${WRKSRC}/build/tmp_build --enable-threads && \
	cd ${WRKSRC}/build/$$(${BIND_SRC_DIR})/lib/dns && \
	${MAKE} include/dns/enumtype.h include/dns/enumclass.h && \
	cd ${WRKSRC}/build/$$(${BIND_SRC_DIR})/lib/bind9 && \
	${MAKE} && ${MAKE} install
	${REINPLACE_CMD} -e 's/-lbind/-lbind9/' ${WRKSRC}/configure \
	${WRKSRC}/enma/bin/Makefile.in ${WRKSRC}/enma/src/Makefile.in
	$$(${CONF_SUB})

post-install:
	${INSTALL_DATA} ${WRKSRC}/enma/etc/enma.conf.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD} "@unexec ${RMDIR} %D/man/ja_JP.UTF-8/man1 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/man/ja_JP.UTF-8 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>

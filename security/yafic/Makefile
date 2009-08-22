# New ports collection makefile for:	yafic
# Date created:		20 August 2001
# Whom:			allan@saddi.com
#
# $FreeBSD$
#

PORTNAME=	yafic
PORTVERSION=	1.2.2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	allan@saddi.com
COMMENT=	Yet Another File Integrity Checker, similar to Tripwire

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LDFLAGS="-static"

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS=	--disable-crypto
PLIST_SUB+=	CRYPTO="@comment "
.else
PLIST_SUB+=	CRYPTO=""
.endif

MAN1=		yafic.1
.if !defined(WITHOUT_OPENSSL)
MAN1+=		yafic-sign.1
MLINKS=		yafic-sign.1 yafic-check.1
.endif
MAN5=		yafic.conf.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yafic ${PREFIX}/bin
.if !defined(WITHOUT_OPENSSL)
	${INSTALL_PROGRAM} ${WRKSRC}/yafic-sign ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/yafic-sign ${PREFIX}/bin/yafic-check
.endif
	${INSTALL_MAN} ${WRKSRC}/yafic.1 ${PREFIX}/man/man1
.if !defined(WITHOUT_OPENSSL)
	${INSTALL_MAN} ${WRKSRC}/yafic-sign.1 ${PREFIX}/man/man1
.endif
	${INSTALL_MAN} ${WRKSRC}/yafic.conf.5 ${PREFIX}/man/man5

post-install:
	@${MKDIR} ${PREFIX}/share/examples/yafic
	@${CP} ${FILESDIR}/yafic.conf.sample ${EXAMPLESDIR}
	@${ECHO}
	@${SED} -e "s%@@PREFIX@@%${PREFIX}%g" ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>

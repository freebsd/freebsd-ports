# Created by: allan@saddi.com
# $FreeBSD$

PORTNAME=	yafic
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	allan@saddi.com
COMMENT=	Yet Another File Integrity Checker, similar to Tripwire

GNU_CONFIGURE=	yes
USES=		gmake
LDFLAGS+=	-static

OPTIONS_DEFINE=	CRYPTO
OPTIONS_DEFAULT=	CRYPTO
OPTIONS_SUB=	yes

CRYPTO_DESC=			Cryptographic support
CRYPTO_USES=			ssl:build
CRYPTO_CONFIGURE_ENABLE=	crypto
CRYPTO_LDFLAGS=			-L${OPENSSLLIB}
CRYPTO_CFLAGS=			-I${OPENSSLINC}

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${SED} -e "s;@@PREFIX@@;${PREFIX};g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yafic ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MCRYPTO}
	${INSTALL_PROGRAM} ${WRKSRC}/yafic-sign ${STAGEDIR}${PREFIX}/bin
	${LN} -sf yafic-sign ${STAGEDIR}${PREFIX}/bin/yafic-check
.endif
	${INSTALL_MAN} ${WRKSRC}/yafic.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MCRYPTO}
	${INSTALL_MAN} ${WRKSRC}/yafic-sign.1 ${STAGEDIR}${PREFIX}/man/man1
	${LN} -sf yafic-sign.1 ${STAGEDIR}${PREFIX}/man/man1/yafic-check.1
.endif
	${INSTALL_MAN} ${WRKSRC}/yafic.conf.5 ${STAGEDIR}${PREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/yafic
	@${CP} ${FILESDIR}/yafic.conf.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

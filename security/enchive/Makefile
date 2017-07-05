# $FreeBSD$

PORTNAME=	enchive
PORTVERSION=	3.2
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Tool to encrypt files to yourself for long-term archival

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	skeeto

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/UNLICENSE

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|CC?|g' -e 's|^CFLAGS|CFLAGS?|g' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/UNLICENSE ${STAGEDIR}/${DATADIR}/UNLICENSE

.include <bsd.port.mk>

# Created by: John Hein <jhein@symmetricom.com>
# $FreeBSD$

PORTNAME=	bbcp
PORTVERSION=	20120520
CATEGORIES=	sysutils net
MASTER_SITES=	https://bitbucket.org/jhein/bbcp/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-20100818.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhein@symmetricom.com
COMMENT=	Secure and fast copy utility

LICENSE=	BSD

USES=		tar:xz
USE_GCC=	yes

PLIST_FILES=	bin/bbcp
PORTDOCS=	${PORTNAME}.pdf

BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|g++|$(CXX)|' -e 's|gcc|$(CC)|' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/FreeBSD/bbcp ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-20100818.pdf \
		${STAGEDIR}${DOCSDIR}/${PORTNAME}.pdf

.include <bsd.port.mk>

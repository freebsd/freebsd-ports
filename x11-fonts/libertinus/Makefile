# $FreeBSD$

PORTNAME=	libertinus
DISTVERSIONPREFIX=	v
DISTVERSION=	6.12
CATEGORIES=	x11-fonts

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Libertinus Open Fonts

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	alerque

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>

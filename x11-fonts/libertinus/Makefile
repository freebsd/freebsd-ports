PORTNAME=	libertinus
DISTVERSION=	7.040
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/alerque/libertinus/releases/download/v${DISTVERSION}/
DISTNAME=	Libertinus-${DISTVERSION}

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Libertinus Open Fonts

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/static/OTF/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>

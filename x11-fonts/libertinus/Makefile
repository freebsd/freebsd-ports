PORTNAME=	libertinus
DISTVERSION=	7.051
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/alerque/libertinus/releases/download/v${DISTVERSION}/
DISTNAME=	Libertinus-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libertinus Open Fonts
WWW=		https://github.com/alerque/libertinus

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts tar:zst

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/static/OTF/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>

PORTNAME=		ibmfonts
DISTVERSIONPREFIX=	v
DISTVERSION=		0.2.0
CATEGORIES=		x11-fonts

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	IBM Fonts in PCF format

LICENSE=	CC-BY-SA-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts
FONTPATHSPEC=	${FONTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	farsil

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--bsd-make \
		--installdir=${FONTSDIR} \
		--prefix=${PREFIX}

NO_ARCH=	yes

.include <bsd.port.mk>

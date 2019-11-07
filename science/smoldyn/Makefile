# $FreeBSD$

PORTNAME=	smoldyn
DISTVERSION=	2.61
CATEGORIES=	science
MASTER_SITES=	http://www.smoldyn.org/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Biochemical simulator for molecular diffusion, surface interactions

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		cmake gl tar:tgz xorg
USE_GL=		gl glu glut
USE_XORG=	xi xmu

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

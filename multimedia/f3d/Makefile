# $FreeBSD$

PORTNAME=	f3d
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and minimalist 3D viewer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libvtkCommonMisc-9.0.so:math/vtk9

USES=		cmake compiler:c++11-lang gl xorg
USE_GITLAB=	yes
GL_SITE=	https://gitlab.kitware.com
GL_COMMIT=	973d8e3b05f2b4275c72f82694e65f1713a87863
USE_GL=		gl glu
USE_XORG=	ice sm x11 xt

PLIST_FILES=	bin/f3d \
		share/applications/f3d.desktop \
		share/icons/hicolor/32x32/apps/f3d.png \
		share/icons/hicolor/48x48/apps/f3d.png \
		share/icons/hicolor/64x64/apps/f3d.png \
		share/icons/hicolor/scalable/apps/f3d.svg

post-install:
	cd ${STAGEDIR}${PREFIX} && ${RM} LICENSE README.md

.include <bsd.port.mk>

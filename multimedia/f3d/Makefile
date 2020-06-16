# $FreeBSD$

PORTNAME=	f3d
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and minimalist 3D viewer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libvtkCommonMisc-9.0.so:math/vtk9

USES=		cmake compiler:c++11-lang gl xorg
USE_GITLAB=	yes
GL_SITE=	https://gitlab.kitware.com
GL_COMMIT=	bbb352f938ccd94a1755b3db643d6896b3f8a3b6
USE_GL=		gl glu
USE_XORG=	ice sm x11 xt

PLIST_FILES=	bin/f3d \
		share/applications/f3d.desktop \
		share/bash-completion/completions/f3d \
		share/fish/vendor_completions.d/f3d.fish \
		share/icons/hicolor/32x32/apps/f3d.png \
		share/icons/hicolor/48x48/apps/f3d.png \
		share/icons/hicolor/64x64/apps/f3d.png \
		share/icons/hicolor/scalable/apps/f3d.svg \
		share/zsh/site-functions/_f3d

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} LICENSE README.md

.include <bsd.port.mk>

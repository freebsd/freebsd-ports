# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	roottail
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.goof.com/pcg/marc/data/
DISTNAME=	root-tail-${PORTVERSION}

.if defined(WITH_EXTRA_PATCH)
PATCH_SITES=	http://bmp-plugins.berlios.de/misc/patches/
PATCHFILES=	roottail-1.2+xfce.diff
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Print text directly to X11 root window

BROKEN=		unfetchable

USES=		imake xorg
USE_XORG=	x11 xext
MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	bin/root-tail \
		man/man1/root-tail.1.gz

pre-everything::
.if defined(WITH_EXTRA_PATCH)
	@${ECHO_MSG}
	@${ECHO_MSG} "Note: this extra patch is not supported by roottail maintainer."
	@${ECHO_MSG} "Before reporting any problems you should build roottail without"
	@${ECHO_MSG} "this option."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>

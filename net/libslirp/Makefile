PORTNAME=	libslirp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.8.0
CATEGORIES=	net

MAINTAINER=	makc@FreeBSD.org
COMMENT=	General purpose TCP-IP emulator library
WWW=		https://gitlab.freedesktop.org/slirp/libslirp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cpe gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CPE_VENDOR=	libslirp_project

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	slirp

.include <bsd.port.mk>

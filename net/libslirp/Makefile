PORTNAME=	libslirp
DISTVERSION=	4.6.1
CATEGORIES=	net

MAINTAINER=	makc@FreeBSD.org
COMMENT=	General purpose TCP-IP emulator library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	slirp
GL_COMMIT=	cceced0cce9d578ed01db68edf31af78eb66f858

.include <bsd.port.mk>

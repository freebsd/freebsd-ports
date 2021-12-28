PORTNAME=	libslirp
DISTVERSION=	4.6.1
CATEGORIES=	net
MASTER_SITES=	https://gitlab.freedesktop.org/slirp/libslirp/-/archive/v${DISTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	General purpose TCP-IP emulator library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		gnome meson pkgconfig tar:bz2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GL_COMMIT=	cceced0cce9d578ed01db68edf31af78eb66f858
WRKSRC=		${WRKDIR}/${PORTNAME}-v${DISTVERSION}-${GL_COMMIT}

.include <bsd.port.mk>

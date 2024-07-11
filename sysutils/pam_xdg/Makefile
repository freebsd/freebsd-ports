PORTNAME=	pam_xdg
DISTVERSION=	0.8.4
CATEGORIES=	sysutils wayland
MASTER_SITES=	https://ftp.sdaoden.eu/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PAM module to manage XDG Base Directories
WWW=		https://www.sdaoden.eu/code.html#s-toolbox

LICENSE=	ISCL

USES=		uidfix
SUB_FILES=	pkg-message
PLIST_FILES=	lib/${PORTNAME}.so \
		share/man/man8/${PORTNAME}.8.gz

# makefile is too crufty, so roll our own
MAKEFILE=	bsd.lib.mk
MAKE_ARGS+=	SHLIB_NAME="${PORTNAME}.so" MAN="${PORTNAME}.8" \
		SRCS="${PORTNAME}.c" LDADD="-lpam" \
		LIBDIR="${PREFIX}/lib" SHAREDIR="${PREFIX}/share"
CFLAGS+=	-DXDG_CONFIG_DIR="${PREFIX}/etc" \
		-DXDG_DATA_DIR_LOCAL="${PREFIX}" \
		-DXDG_RUNTIME_DIR_OUTER="/var/run"
LDFLAGS+=	-Wl,-z,defs

.include <bsd.port.mk>

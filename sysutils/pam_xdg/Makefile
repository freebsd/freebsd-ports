PORTNAME=	pam_xdg
PORTVERSION=	s20210916
PORTREVISION=	1
CATEGORIES=	sysutils wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PAM module to manage XDG Base Directories

LICENSE=	ISCL

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	sdaoden
GH_PROJECT=	s-toolbox
GH_TAGNAME=	cdbe3ce
PLIST_FILES=	lib/${PORTNAME}.so \
		share/man/man8/${PORTNAME}.8.gz

# pam_xdg.makefile is too crufty, so roll our own
MAKEFILE=	bsd.lib.mk
MAKE_ARGS+=	SHLIB_NAME="${PORTNAME}.so" MAN="${PORTNAME}.8" \
		SRCS="${PORTNAME}.c" LDADD="-lpam" \
		LIBDIR="${PREFIX}/lib" SHAREDIR="${PREFIX}/share"
CFLAGS+=	-DXDG_CONFIG_DIR="${PREFIX}/etc" \
		-DXDG_DATA_DIR_LOCAL="${PREFIX}" \
		-DXDG_RUNTIME_DIR_OUTER="/var/run"
LDFLAGS+=	-Wl,-z,defs

.include <bsd.port.mk>

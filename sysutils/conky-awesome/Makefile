PKGNAMESUFFIX=	-awesome

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced, highly configurable system monitor (configured for x11-wm/awesome)

MASTERDIR=	${.CURDIR}/../conky
DESCR=		${.CURDIR}/pkg-descr

CONFLICTS=	conky

OPTIONS_EXCLUDE=	ARGB DOUBLE_BUFFER IMLIB2 MOUSE_EVENTS XFT XINERAMA LUA_CAIRO \
			LUA_IMLIB2 LUA_RSVG WAYLAND

.include "${MASTERDIR}/Makefile"

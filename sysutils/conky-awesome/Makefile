PKGNAMESUFFIX=	-awesome

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Advanced, highly configurable system monitor (configured for x11-wm/awesome)

MASTERDIR=	${.CURDIR}/../conky
DESCR=		${.CURDIR}/pkg-descr

CONFLICTS=	conky

OPTIONS_EXCLUDE=	X11 ARGB DOUBLE_BUFFER IMLIB2 XFT XINERAMA LUA_CAIRO LUA_IMLIB2 \
			LUA_RSVG

.include "${MASTERDIR}/Makefile"

# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-awesome

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	An advanced, highly configurable system monitor (configured for x11-wm/awesome)

MASTERDIR=	${.CURDIR}/../conky
DESCR=		${.CURDIR}/pkg-descr

CONFLICTS=	conky-[0-9]*

OPTIONS_EXCLUDE=	X11
OPTIONS_GROUP=
OPTIONS_DEFAULT=

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"

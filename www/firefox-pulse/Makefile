# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

COMMENT=	Firefox built with pulseaudio support

SLAVE_PORT=	firefox

CONFLICTS=	firefox-[0-9]*

OPTIONS_SET=	PULSEAUDIO

MASTERDIR=	${.CURDIR}/../firefox
PLIST=		${MASTERDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"

PKGNAMESUFFIX=	-pulse

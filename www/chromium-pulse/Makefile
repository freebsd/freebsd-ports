# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

COMMENT=	Chromium built with PULSEAUDIO

SLAVE_PORT=	chromium

CONFLICTS=	chromium-[0-9]*

OPTIONS_SET=	PULSEAUDIO

MASTERDIR=	${.CURDIR}/../chromium
PLIST=		${MASTERDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"

PKGNAMESUFFIX=	-pulse

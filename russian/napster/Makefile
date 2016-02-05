# Created by: Roman Y. Bogdanov <sam@brj.pp.ru>
# $FreeBSD$

PORTNAME=	nap
CATEGORIES=	russian

MAINTAINER=	sam@brj.pp.ru
COMMENT=	Client for the OpenNAP network with koi8 <> win1251 encoding patch

MASTERDIR=	${.CURDIR}/../../audio/napster

CONFLICTS=	nap-[0-9]*

USES=		ncurses
WITH_ENCODING_PATCH=	yes

pre-configure:
	@${PATCH} ${PATCH_ARGS} < ${.CURDIR}/files/extra-win2koi

.include "${MASTERDIR}/Makefile"

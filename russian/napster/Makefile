# New ports collection makefile for:	napster
# Date created:				21.07.2004
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	nap
CATEGORIES=	russian

MAINTAINER=	sam@brj.pp.ru
COMMENT=	Client for the OpenNAP network with koi8 <> win1251 encoding patch

MASTERDIR=	${.CURDIR}/../../audio/napster

CONFLICTS=	nap-[0-9]*

WITH_ENCODING_PATCH=	yes

pre-configure:
	@${PATCH} ${PATCH_ARGS} < ${.CURDIR}/files/extra-win2koi

.include "${MASTERDIR}/Makefile"

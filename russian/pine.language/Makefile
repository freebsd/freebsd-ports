# New ports collection makefile for:    ru-pine
# Whom:                 ache
# Date created:		1996/12/03
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	4.21
CATEGORIES=	russian mail
EXTRACT_ONLY=	# empty

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Tune Pine for Russian (KOI8-R) defaults

RUN_DEPENDS=	pine:${PORTSDIR}/mail/pine4

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_FILES=	etc/pine.conf

do-fetch:

do-install:
	${GREP} -q -i koi8 ${PREFIX}/etc/pine.conf || \
		${CAT} ${FILESDIR}/pine.add >> \
		${PREFIX}/etc/pine.conf

.include <bsd.port.mk>

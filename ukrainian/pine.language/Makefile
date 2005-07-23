# New ports collection makefile for:    uk-pine
# Whom:					Olexander Kunytsa <kunia@istc.kiev.ua>
# Date created:				17 April 2001
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	4.33
CATEGORIES=	ukrainian mail news
EXTRACT_ONLY=	# empty

MAINTAINER=	kunia@istc.kiev.ua
COMMENT=	Tune Pine for Ukrainian (KOI8-U) defaults

RUN_DEPENDS=	pine:${PORTSDIR}/mail/pine4

BROKEN=		Removes config file at deinstall-time
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
PLIST_FILES=	etc/pine.conf

do-fetch:

do-install:
	${GREP} -q -i koi8 ${PREFIX}/etc/pine.conf || \
		${CAT} ${FILESDIR}/pine.add >> \
		${PREFIX}/etc/pine.conf

.include <bsd.port.mk>

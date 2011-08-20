# New ports collection makefile for:	bugzilla-ru
# Date created:	   28 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
DISTVERSION=	4.0.2-ru-20110808
CATEGORIES=	russian
MASTER_SITES=	http://ftp.mozilla-russia.org/bugzilla/
PKGNAMESUFFIX=	-ru

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Russian localization for Bugzilla

RUN_DEPENDS=	bugzilla>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/r.*$/ru/}

.include "${.CURDIR}/../../devel/bugzilla/Makefile.common"

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${PAX} -r -w * ${WWWDIR})
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>

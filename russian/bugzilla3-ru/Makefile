# New ports collection makefile for:	bugzilla-ru
# Date created:	   28 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	bugzilla
DISTVERSION=	3.6.9-ru-20120419
CATEGORIES=	russian
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=bugzilla-ru/bugzilla-3.6-ru/${PORTVERSION:R:R}
PKGNAMESUFFIX=	-ru

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Russian localization for Bugzilla

RUN_DEPENDS=	bugzilla>=${PORTVERSION}:${PORTSDIR}/devel/bugzilla3

LATEST_LINK=	${PKGNAMEPREFIX}bugzilla3${PKGNAMESUFFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/r.*$/ru/}

.include "${.CURDIR}/../../devel/bugzilla3/Makefile.common"

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${PAX} -r -w * ${WWWDIR})
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>

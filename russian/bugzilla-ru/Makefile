# New ports collection makefile for:	bugzilla-ru
# Date created:	   28 Jul 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	bugzilla-ru
DISTVERSION=	3.2rc2-ru-1.0
CATEGORIES=	russian
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	bugzilla-${DISTVERSION}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Russian localization for Bugzilla

RUN_DEPENDS=	bugzilla>=3.2:${PORTSDIR}/devel/bugzilla

CONFLICTS?=	ja-bugzilla-2.* bugzilla-2.*

PORTSCOUT=	limitw:1,even

.ifndef BUGZILLADIR
.ifdef APACHE_DATADIR
BUGZILLADIR=	${APACHE_DATADIR}/data/bugzilla
.else
BUGZILLADIR=	${PREFIX}/www/data/bugzilla
.endif
.endif

PLIST_SUB+=	BUGZILLADIR=${BUGZILLADIR:S!^${PREFIX}/!!}

NO_BUILD=	yes

do-install:
	${MKDIR} ${BUGZILLADIR}
	${TAR} -C ${WRKSRC} -cf - . | \
		${TAR} --unlink -C ${BUGZILLADIR} -xf -
.if !defined(BATCH)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>

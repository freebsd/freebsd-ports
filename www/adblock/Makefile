# Ports collection makefile for:  adblock
# Date created:			  Thu Aug 4, 2005
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	adblock
DISTVERSION=	0.5-dev
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A content filtering plug-in for ${GECKO}

PLIST_FILES=	%%MOZDIR%%/chrome/adblock.jar

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

.if ${GECKO} == mozilla
PLIST_FILES+=	%%MOZDIR%%/chrome/overlayinfo/mozapps/content/overlays.rdf
.endif

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/adblock.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

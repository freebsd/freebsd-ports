# Ports collection makefile for:  preferential
# Date created:			  Tue Oct 28, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	preferential
PORTVERSION=	0.8.1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}/versions
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	GUI interface to view & edit all ${GECKO} prefs

PLIST_FILES=	%%MOZDIR%%/chrome/preferential.jar

PORTSCOUT=	skipv:0.8.2

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

.if ${GECKO} == mozilla
PLIST_FILES+=	%%MOZDIR%%/chrome/overlayinfo/browser/content/overlays.rdf
.endif

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/preferential.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

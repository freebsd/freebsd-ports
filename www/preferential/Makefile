# Ports collection makefile for:  preferential
# Date created:			  Tue Oct 28, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	preferential
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}/versions
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI interface to view & edit all ${GECKO} prefs

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.

PLIST_FILES=	%%MOZDIR%%/chrome/preferential.jar

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

.if ${GECKO} == mozilla
PLIST_FILES+=	%%MOZDIR%%/chrome/overlayinfo/browser/content/overlays.rdf
.endif

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/preferential.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

# Ports collection makefile for:  adblock
# Date created:			  Thu Aug 4, 2005
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME?=	adblock
DISTVERSION=	0.5-dev
PORTREVISION?=	0
CATEGORIES=	www
MASTER_SITES=	http://www.devlib.org/mozdev/adblock/	\
		http://downloads.mozdev.org/adblock/	\
		http://ftp.ntua.gr/pub/www/mozdev/adblock/	\
		http://ftp.iasi.roedu.net/mirrors/mozdev.org/adblock/
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	A content filtering plug-in for Mozilla

USE_X_PREFIX=	yes

PLIST_FILES=	%%MOZDIR%%/chrome/adblock.jar	\
		%%MOZDIR%%/chrome/overlayinfo/mozapps/content/overlays.rdf

SLAVEDIRS=	www/adblock-firefox

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/adblock.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

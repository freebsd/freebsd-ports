# Ports collection makefile for:  mozex
# Date created:			  Sun Oct 26, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#    $MCom: ports/www/mozex/Makefile,v 1.2 2006/09/22 19:52:59 mezz Exp $
#

PORTNAME=	mozex
PORTVERSION=	1.07
PORTREVISION=	8
CATEGORIES=	www mail news ftp
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mozex allows users of ${GEKO} to use external programs for mail, news, etc.

SUB_FILES=	pkg-message
SUB_LIST=	GECKO=${GECKO}
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	%%MOZDIR%%/chrome/mozex.jar

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

.if ${GECKO} == mozilla
PLIST_FILES+=	%%MOZDIR%%/chrome/overlayinfo/browser/content/overlays.rdf
.endif

do-install:
	@${INSTALL_DATA} ${WRKDIR}/mozex.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

# Ports collection makefile for:  preferential
# Date created:			  Tue Oct 28, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME?=	preferential
PORTVERSION=	0.7.1
PORTREVISION?=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}/versions
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	GUI interface to view & edit all Mozilla prefs

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/preferential.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

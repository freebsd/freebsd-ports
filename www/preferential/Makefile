# Ports collection makefile for:  preferential
# Date created:			  Tue Oct 28, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME?=	preferential
PORTVERSION=	0.6.1a
PORTREVISION?=	2
CATEGORIES=	www
MASTER_SITES=	http://downloads.mozdev.org/preferential/versions/	\
		http://mozdev.mirrors.nyphp.org/preferential/versions/
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	GUI interface to view & edit all Mozilla prefs

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

do-install:
	@${INSTALL_DATA} ${WRKDIR}/preferential.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

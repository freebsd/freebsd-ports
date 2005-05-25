# Ports collection makefile for:  preferential
# Date created:			  Tue Oct 28, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME?=	preferential
PORTVERSION=	0.7.1
PORTREVISION?=	0
CATEGORIES=	www
MASTER_SITES=	http://downloads.mozdev.org/preferential/versions/	\
		http://ftp.ntua.gr/pub/www/mozdev/preferential/versions/	\
		http://ftp.iasi.roedu.net/mirrors/mozdev.org/preferential/versions/
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	GUI interface to view & edit all Mozilla prefs

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

do-install:
	@${INSTALL_DATA} ${WRKDIR}/chrome/preferential.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

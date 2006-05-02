# Ports collection makefile for:  mozex
# Date created:			  Sun Oct 26, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME?=	mozex
PORTVERSION=	1.07
PORTREVISION?=	3
CATEGORIES=	www mail news ftp
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Mozex allows Mozilla's users to use external programs for mail, news, etc.

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

do-install:
	@${INSTALL_DATA} ${WRKDIR}/mozex.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

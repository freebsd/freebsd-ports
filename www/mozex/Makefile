# Ports collection makefile for:  mozex
# Date created:			  Sun Oct 26, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME?=	mozex
PORTVERSION=	1.07
PORTREVISION?=	2
CATEGORIES=	www mail news ftp
MASTER_SITES=	http://downloads.mozdev.org/mozex/	\
		http://mozdev.sweetooth.org/mozex/

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Mozex allows Mozilla's users to use external programs for mail, news, etc.

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

do-install:
	@${INSTALL_DATA} ${WRKDIR}/mozex.jar ${MOZDIR}/chrome

.include <bsd.port.post.mk>

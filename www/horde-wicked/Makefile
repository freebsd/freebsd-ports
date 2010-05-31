# Ports collection makefile for:  horde-wicked
# Date created:			  Jul 20, 2008
# Whom:				  Beech Rintoul <beech@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wicked
DISTVERSIONPREFIX?=
DISTVERSION=	0.0.20080730
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES?=	LOCAL/beech \
		http://www.alaskaparadise.com/freebsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wiki module for Horde

USE_HORDE=	base pkg-message
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL TODO

BUILD_DEPENDS+=	${PEARDIR}/Text/Wiki.php:${PORTSDIR}/www/pear-Text_Wiki

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>

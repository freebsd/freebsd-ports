# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wicked
DISTVERSIONPREFIX?=
DISTVERSION=	0.0.20080730
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES?=	LOCAL/beech \
		http://www.alaskaparadise.com/freebsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wiki module for Horde

USE_HORDE=	base pkg-message
USES=		gettext
PORTDOCS=	README CHANGES CREDITS INSTALL TODO

BUILD_DEPENDS+=	${PEARDIR}/Text/Wiki.php:${PORTSDIR}/www/pear-Text_Wiki

NO_STAGE=	yes
.include "${.CURDIR}/../../www/horde3-base/bsd.horde.mk"
.include <bsd.port.mk>

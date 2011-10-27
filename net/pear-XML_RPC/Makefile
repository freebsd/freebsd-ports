# Ports collection makefile for:  pear-XML_RPC
# Date created:		7 Feb 2007
# Whom:			Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML_RPC
PORTVERSION=	1.5.5
CATEGORIES=	net devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP implementation of the XML-RPC protocol

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	xml
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>

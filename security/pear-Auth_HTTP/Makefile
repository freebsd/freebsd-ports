# Ports collection makefile for:	pear-Auth_HTTP
# Date created:				2004-10-25
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	Auth_HTTP
PORTVERSION=	2.0
CATEGORIES=	security www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR HTTP authentication methods

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR \
		${PEARDIR}/Auth/Auth.php:${PORTSDIR}/security/pear-Auth
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Auth
FILES=		Auth_HTTP.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>

# New ports collection makefile for:	pecl-ssh2
# Date created:			20050407
# Whom:				Alexander Leidinger <netchild@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssh2
PORTVERSION=	0.9
CATEGORIES=	security pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	ssh2-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PECL extension to the libssh2 library

LIB_DEPENDS=	ssh2:${PORTSDIR}/security/libssh2

USE_PHP=	yes
USE_PHPEXT=	yes

.include <bsd.port.mk>

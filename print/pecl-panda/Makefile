# New ports collection makefile for:	pecl-panda
# Date created:			25 Jun 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	panda
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	print pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to create PDF documents

LIB_DEPENDS=	panda.0:${PORTSDIR}/print/panda

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-panda=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Panda shared library doesn't export required symbols
.endif

.include <bsd.port.post.mk>

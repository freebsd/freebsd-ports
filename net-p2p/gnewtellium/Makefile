# New ports collection makefile for:	gnewtellium
# Date created:				9 April 2002
# Whom:					haikal
#
# $FreeBSD$

PORTNAME=	gnewtellium
PORTVERSION=	0.05b
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wyldephyre2@yahoo.com
COMMENT=	A gnutella client

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	napshare
# Date created:				4 July 2001
# Whom:					Mike Heffner <mikeh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	napshare
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	napshare

MAINTAINER=	mikeh@FreeBSD.org
COMMENT=	A GTK based Gnutella client

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-extract:
	@${RM} ${WRKSRC}/config.cache

.include <bsd.port.mk>

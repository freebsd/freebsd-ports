# New ports collection makefile for:	gtkyahoo
# Date created:			18 August 1999
# Whom:				dannyman@dannyland.org
#
# $FreeBSD$
#

PORTNAME=	gtkyahoo
PORTVERSION=	0.18.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkyahoo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yahoo Messenger Client using GTK

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_BISON=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>

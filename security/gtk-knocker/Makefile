# New ports collection makefile for:	gtk-knocker
# Date created:				Tue Jul 10 02:18:39 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	knocker
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	security net x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gtk-
DISTNAME=	gtk-${PORTNAME}-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A simple and easy to use TCP only port scanner (GTK+ version)

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes
USE_GNOME=	gtk12

MAN1=		gtk-knocker.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/gtk-knocker.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>

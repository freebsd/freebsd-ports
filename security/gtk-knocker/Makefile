# New ports collection makefile for:	gtk-knocker
# Date created:				Tue Jul 10 02:18:39 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	knocker
PORTVERSION=	0.2.0
CATEGORIES=	security net x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gtk-
DISTNAME=	gtk-${PORTNAME}-${PORTVERSION}

MAINTAINER=	pat@databits.net

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes
USE_GTK=	yes

MAN1=		gtk-knocker.1

pre-patch:
	@${PERL} -pi -e 's|gtk-config|${GTK_CONFIG}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

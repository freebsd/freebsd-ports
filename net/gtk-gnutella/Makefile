# New ports collection makefile for:	gtk-gnutella
# Date created:				19 May, 2000
# Whom:					rbt@zort.on.ca
#
# $FreeBSD$
#

PORTNAME=	gtk-gnutella
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://gtk-gnutella.sourceforge.net/download/ \
		ftp://gtk-gnutella.sourceforge.net/pub/gtk-gnutella/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-no-rfc1918

.include <bsd.port.mk>

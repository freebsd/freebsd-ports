# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomemeeting
PORTVERSION=	0.10
CATEGORIES=	net gnome
MASTER_SITES=	http://130.104.229.225/gnomemeeting/downloads/ \
		ftp://telepresence.dmem.strath.ac.uk/pub/openh323/

MAINTAINER=	roger@FreeBSD.org

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf/

BUILD_DEPENDS=  ${NONEXISTENT}:${PORTSDIR}/net/openh323:build

# note, we do not want to clean openh323, otherwise it has to build
# it all over again which can take several hours.
NOCLEANDEPENDS= yes

#USE_X_PREFIX=   yes
USE_NEWGCC=     yes
USE_GNOME=	yes
USE_AUTOCONF=	yes
USE_GTK=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LIBS=-L${PREFIX}/lib \
		PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
post-patch:
		rm ${WRKSRC}/config.cache

.include <bsd.port.mk>

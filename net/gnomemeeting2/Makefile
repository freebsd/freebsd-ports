# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomemeeting
PORTVERSION=	0.12.2
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	http://www.gnomemeeting.org/downloads/latest/sources/
DISTNAME=	GnomeMeeting-0.12.2

MAINTAINER=	roger@FreeBSD.org

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf/

BUILD_DEPENDS=  ${NONEXISTENT}:${PORTSDIR}/net/openh323:build

# note, we do not want to clean openh323, otherwise it has to build
# it all over again which can take several hours.
NOCLEANDEPENDS= yes

USE_NEWGCC=     yes
USE_GNOME=	yes
USE_AUTOCONF=	yes
USE_GTK=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	 --with-ptlib-includes=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib/include/ptlib \
		 --with-ptlib-libs=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib/lib \
		 --with-openh323-includes=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323/include \
		 --with-openh323-libs=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323/lib \
		--with-ldap=/usr/local
CONFIGURE_ENV=	LIBS=-L${PREFIX}/lib \
		PTLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323 \

.include <bsd.port.mk>

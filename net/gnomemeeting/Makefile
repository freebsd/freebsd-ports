# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomemeeting
PORTVERSION=	0.85.1
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	http://www.gnomemeeting.org/downloads/0.85/sources/
DISTNAME=	GnomeMeeting-0.85.1

MAINTAINER=	roger@FreeBSD.org

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap
BUILD_DEPENDS=  ${NONEXISTENT}:${PORTSDIR}/net/openh323:build

# note, we do not want to clean openh323, otherwise it has to build
# it all over again which can take several hours.
NOCLEANDEPENDS= yes

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_AUTOCONF=	yes		# we need this so configure is regenerated
USE_GNOMENG=	yes
USE_GNOME=	gnomecanvas gnomelibs gnomehack gnomeprefix gconf
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-ptlib-includes=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib/include/ptlib \
		--with-ptlib-libs=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib/lib \
		--with-openh323-includes=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323/include \
		--with-openh323-libs=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323/lib \
		--with-ldap=${LOCALBASE}
CONFIGURE_ENV=	OSTYPE=${OPSYS} \
		LIBS=-L${PREFIX}/lib \
		PTLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323

.include <bsd.port.mk>

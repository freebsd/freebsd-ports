# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnomemeeting
PORTVERSION=	0.94.1
CATEGORIES=	net gnome
MASTER_SITES=	http://www.gnomemeeting.org/downloads/0.94.1/sources/

MAINTAINER=	roger@FreeBSD.org

LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2 \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		bonobo-2.0:{PORTSDIR}/devel/libbonobo
BUILD_DEPENDS=  ${NONEXISTENT}:${PORTSDIR}/net/openh323:build

# note, we do not want to clean openh323, otherwise it has to build
# it all over again which can take several hours.
NOCLEANDEPENDS= yes

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gdkpixbuf gnomelibs gnomehack gnomeprefix gconf bonobo esound
USE_BISON=	yes
# Clear configure target so we stop getting binaries prefixed with i386-portbld-freebsd46
CONFIGURE_TARGET=
GNU_CONFIGURE=	YES
CONFIGURE_ENV=  OSTYPE=${OPSYS} \
		LIBS="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
		PTLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323 \
		SDL_CONFIG=${LOCALBASE}/bin/sdl11-config \
		CPPFLAGS="-I${LOCALBASE}/include"

CONFIGURE_ARGS= --with-ptlib-includes=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib/include/ptlib \
		--with-ptlib-libs=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib/lib \
		--with-openh323-includes=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323/include \
		--with-openh323-libs=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323/lib \
		--with-ldap-includes=${LOCALBASE}/include \
		--with-openldap-libs=${LOCALBASE}/lib

MAN1=		gnomemeeting.1
.include <bsd.port.mk>

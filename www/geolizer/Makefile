# New ports collection makefile for:    geolizer
# Date created:         23 July 2004
# Whom:                 ache@FreeBSD.org
#
# $FreeBSD$
#

CONFLICTS=	webalizer-2*

MASTERDIR=      ${.CURDIR}/../webalizer

PATCH_SITES+=	http://sysd.org/proj/
PATCHFILES+=	geolizer_2.01-10-patch.20040216.tar.bz2
PATCH_DIST_STRIP= -p1
PATCHDIR=	${.CURDIR}/files
MD5_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
DOCSDIR=	${PREFIX}/share/doc/webalizer
EXAMPLESDIR=	${PREFIX}/share/examples/webalizer

WEBALIZER_LANG=english

CFLAGS+= -I${LOCALBASE}/include
CONFIGURE_ARGS+= --enable-geoip \
		--with-geoip-lib=${LOCALBASE} \
		--with-geoip-inc=${LOCALBASE}

LIB_DEPENDS=    gd.4:${PORTSDIR}/graphics/gd \
		GeoIP.4:${PORTSDIR}/net/GeoIP

MAINTAINER=	ports@FreeBSD.org

.include "${MASTERDIR}/Makefile"

# Overwrite section, can't be placed before

PORTNAME=	geolizer
PORTREVISION=	0
DISTNAME=       webalizer-2.01-10-src

COMMENT=	A web server log file analysis program, using GeoIP library


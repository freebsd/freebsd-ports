# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	redland
PORTVERSION=	0.9.10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xmlparse.1:${PORTSDIR}/www/libwww \
		expat.2:${PORTSDIR}/textproc/expat2 \
		gdbm:${PORTSDIR}/databases/gdbm \
		db2:${PORTSDIR}/databases/db

USE_OPENSSL=	yes
LIBWWW_CONFIG=	${LOCALBASE}/bin/libwww-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} `${LIBWWW_CONFIG} --cflags` -I${LOCALBASE}/include/db2" \
		LDFLAGS="`${LIBWWW_CONFIG} --libs`"
CONFIGURE_ARGS=	--with-bdb=${LOCALBASE} --with-libwww

.include <bsd.port.mk>

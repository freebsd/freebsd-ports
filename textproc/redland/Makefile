# ex:ts=8
# New ports collection makefile for:	redland
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	redland
PORTVERSION=	0.9.11
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2 \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		expat.4:${PORTSDIR}/textproc/expat2 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xmlparse.1:${PORTSDIR}/www/libwww

LIBWWW_CONFIG?=	${LOCALBASE}/bin/libwww-config

USE_OPENSSL=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-bdb=${LOCALBASE} --with-libwww
INSTALLS_SHLIB=	yes

MAN3=		redland.3

CPPFLAGS=	-I${LOCALBASE}/include/db2 -I${LOCALBASE}/include \
		`${LIBWWW_CONFIG} --cflags`
LDFLAGS=	-L${LOCALBASE}/lib `${LIBWWW_CONFIG} --libs`

.include <bsd.port.mk>

# ex:ts=8
# New ports collection makefile for:	raptor
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	raptor
PORTVERSION=	0.9.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xmlparse.1:${PORTSDIR}/www/libwww

LIBWWW_CONFIG=	${LOCALBASE}/bin/libwww-config

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		rdfdump.1
MAN3=		libraptor.3

CPPFLAGS=	-I${LOCALBASE}/include `${LIBWWW_CONFIG} --cflags`
LDFLAGS=	-L${LOCALBASE}/lib -lgnugetopt `${LIBWWW_CONFIG} --libs`

.include <bsd.port.mk>

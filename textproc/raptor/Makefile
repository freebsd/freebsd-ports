# ex:ts=8
# New ports collection makefile for:	raptor
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	raptor
PORTVERSION=	0.9.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2 \
		xmlparse:${PORTSDIR}/www/libwww \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

LIBWWW_CONFIG=	${LOCALBASE}/bin/libwww-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include `${LIBWWW_CONFIG} --cflags`" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt `${LIBWWW_CONFIG} --libs`"

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	serveez
# Date created:			May 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	serveez
PORTVERSION=	0.1.3
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt \
		bz2:${PORTSDIR}/archivers/bzip2

GUILE_CONFIG?=	${LOCALBASE}/bin/guile-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include `${GUILE_CONFIG} compile`" \
	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt `${GUILE_CONFIG} link`"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	serveez.1

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	serveez
# Date created:			May 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	serveez
PORTVERSION=	0.1.4
PORTREVISOIN=	0
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.textsure.net/~ela/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		guile.10:${PORTSDIR}/lang/guile
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

GUILE_CONFIG?=	${LOCALBASE}/bin/guile-config

USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `${GUILE_CONFIG} compile`" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt `${GUILE_CONFIG} link`"
INSTALLS_SHLIB=	yes

MAN1=	serveez.1

.include <bsd.port.mk>

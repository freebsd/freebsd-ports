# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblrdf
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	icuuc:${PORTSDIR}/devel/icu \
		yajl:${PORTSDIR}/devel/yajl \
		curl:${PORTSDIR}/ftp/curl \
		raptor2:${PORTSDIR}/textproc/raptor2

USE_AUTOTOOLS=	libtoolize automake autoconf aclocal
ACLOCAL_ARGS=	-I${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_ICONV=	yes
USE_GNOME=	gnomehack libxml2 libxslt
GNOME_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CFLAGS+=	-I${OPENSSLINC} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${OPENSSLLIB} ${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/swh-LRDF-7ebc032

.include <bsd.port.mk>

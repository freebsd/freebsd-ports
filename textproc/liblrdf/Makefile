# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblrdf
PORTVERSION=	0.5.0
PORTREVISION=	2
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
USES=		pathfix pkgconfig iconv
USE_GNOME=	libxml2 libxslt
GNOME_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

CFLAGS+=	-I${OPENSSLINC} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${OPENSSLLIB} ${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/swh-LRDF-7ebc032

.include <bsd.port.mk>

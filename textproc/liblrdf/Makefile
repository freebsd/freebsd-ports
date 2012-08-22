# New ports collection Makefile for:	liblrdf
# Date created:				26 April 2003
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liblrdf
PORTVERSION=	0.5.0
CATEGORIES=	textproc
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	raptor2:${PORTSDIR}/textproc/raptor2

USE_AUTOTOOLS=	libtoolize automake autoconf aclocal
ACLOCAL_ARGS=	-I${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
GNOME_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CFLAGS+=	-I${OPENSSLINC} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${OPENSSLLIB} ${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/swh-LRDF-7ebc032

.include <bsd.port.mk>

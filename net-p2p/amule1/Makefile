# New ports collection makefile for:	amule
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#    $MCom: ports/net-p2p/amule1/Makefile,v 1.1 2006/10/04 23:22:32 ahze Exp $

PORTNAME=	aMule
PORTVERSION=	1.2.8
PORTREVISION=	5
CATEGORIES=	net-p2p
#MASTER_SITES=	http://download.berlios.de/amule/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	amule

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The all-platform eMule p2p client

DEPRECATED=	use net-p2p/amule2 if you are running OSVERSION > 500000

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

LATEST_LINK=	aMule1
CONFLICTS=	aMule-2.* aMule-devel-[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehier gnomehack gnomeprefix
USE_GMAKE=	yes
USE_WX=		2.4
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-wxbase-config=${WX_CONFIG} \
		--with-curl-config=${CURL_CONFIG} \
		--program-transform-name="s/ed2k/amule-ed2k-handler/"

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	OPTIMIZE "Build with optimization" on \
		STATIC "Enable static linking" off

CURL_CONFIG?=	${LOCALBASE}/bin/curl-config

.include <bsd.port.pre.mk>

# Configure options
.if !defined(WITHOUT_OPTIMIZE)
CONFIGURE_ARGS+=	--enable-optimise
.endif

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=	--enable-static
.endif

.include <bsd.port.post.mk>

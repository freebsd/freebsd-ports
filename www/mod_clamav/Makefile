# New ports collection makefile for:	mod_clamav
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_clamav
PORTVERSION=	0.21
CATEGORIES=	www security
MASTER_SITES=	http://software.othello.ch/mod_clamav/

MAINTAINER=	tmueko@kommunity.net
COMMENT=	Scans content delivered by the Apache2 proxy module for viruses

LIB_DEPENDS+=	clamav:${PORTSDIR}/${CLAMAV_PORT}

USE_APACHE=	YES
WITH_APACHE2=	YES
USE_LIBTOOL_VER=13

.if defined(WITH_CLAMAVDEVEL)
CLAMAV_PORT=	security/clamav-devel
.else
CLAMAV_PORT=	security/clamav
.endif

CONFIGURE_ARGS=	--with-apxs=${PREFIX}/sbin/apxs \
		--libdir=${PREFIX}/lib/apache2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${PTHREAD_LIBS}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

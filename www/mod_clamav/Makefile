# New ports collection makefile for:	mod_clamav
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_clamav
PORTVERSION=	0.22
PORTREVISION=	4
CATEGORIES=	www security
MASTER_SITES=	http://software.othello.ch/mod_clamav/ \
		http://www.kommunity.net/download/mod_clamav/

MAINTAINER=	tmueko@kommunity.net
COMMENT=	Scans content delivered by the Apache20 proxy module for viruses

USE_AUTOTOOLS=	libtool:15
USE_APACHE=	2.0
WITH_APACHE2=	YES
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache22/http_core.h) || exists(${LOCALBASE}/include/apache/http_core.h)
IGNORE=	mod_clamav only compile and run with apache-2.0.x
.endif

.if defined(WITH_CLAMAVDEVEL)
LIB_DEPENDS+=	clamav.6:${PORTSDIR}/security/clamav-devel
.else
CLAMAV_PORT=	security/clamav
LIB_DEPENDS+=	clamav.6:${PORTSDIR}/security/clamav
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
.include <bsd.port.post.mk>

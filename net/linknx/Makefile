# New ports collection makefile for:	linknx
# Date Created:				23 October 2008
# Whom:					Björn König <bkoenig@alpha-tierchen.de>
#
# $FreeBSD$
#

PORTNAME=	linknx
PORTVERSION=	0.0.1.25
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Rule-based event handling in a KNX installation

LIB_DEPENDS=	pthsem.20:${PORTSDIR}/devel/pthsem
BUILD_DEPENDS=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-I${LOCALBASE}/include -L/${LOCALBASE}/lib"

OPTIONS=	LIBESMTP "Install libesmtp for SMTP support" on \
		LIBCURL "Install libcurl for Clickatell SMS support" off

.include <bsd.port.pre.mk>

.if (defined(WITH_LIBESMTP) || exists(${LOCALBASE}/include/libesmtp.h))
CONFIGURE+=	--enable-smtp
LIB_DEPENDS+=	esmtp.6:${PORTSDIR}/mail/libesmtp
.endif

.if (defined(WITH_LIBCURL) || exists(${LOCALBASE}/lib/libcurl.so))
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
.endif

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.post.mk>

# Created by: Björn König <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	linknx
PORTVERSION=	0.0.1.25
PORTREVISION=	4
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

OPTIONS_DEFINE=	LIBESMTP LIBCURL
OPTIONS_DEFAULT=	LIBESMTP
LIBESMTP_DESC=	Install libesmtp for SMTP support
LIBCURL_DESC=	Install libcurl for Clickatell SMS support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLIBESMTP}
CONFIGURE_ARGS+=	--enable-smtp
LIB_DEPENDS+=	esmtp.7:${PORTSDIR}/mail/libesmtp
.else
CONFIGURE_ARGS+=	--disable-smtp
.endif

.if ${PORT_OPTIONS:MLIBCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-libcurl=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libcurl
.endif

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.post.mk>

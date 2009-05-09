# New ports collection makefile for:	tinyproxy
# Date created:		01 Jul 1999
# Whom:			Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	tinyproxy
PORTVERSION=	1.6.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	https://www.banu.com/pub/tinyproxy/1.6/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A small, efficient HTTP proxy server

USE_RC_SUBR=	tinyproxy.sh
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--with-config=${PREFIX}/etc/tinyproxy.conf \
		--program-transform-name=""
MAKE_JOBS_SAFE=	yes

MAN8=		tinyproxy.8

OPTIONS=	REVERSE "Enable reverse proxy support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_REVERSE)
CONFIGURE_ARGS+=	--enable-reverse
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/tinyproxy/tinyproxy.conf|${PREFIX}/etc/tinyproxy.conf|' \
	  ${WRKSRC}/doc/tinyproxy.8
	@${REINPLACE_CMD} -e 's|/usr/share/tinyproxy|${DATADIR}|' \
	  ${WRKSRC}/doc/tinyproxy.conf

post-install:
	@if [ ! -f ${PREFIX}/etc/tinyproxy.conf ]; then \
		${CP} -p ${PREFIX}/etc/tinyproxy.conf-dist \
		${PREFIX}/etc/tinyproxy.conf ; \
	fi

.include <bsd.port.post.mk>

# New ports collection makefile for:	tinyproxy
# Date created:		01 Jul 1999
# Whom:			Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	tinyproxy
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	A small, efficient HTTP proxy server

USE_RC_SUBR=	tinyproxy.sh
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--with-config=${PREFIX}/etc/tinyproxy.conf \
		--program-transform-name=""

MAN8=		tinyproxy.8

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc/tinyproxy/tinyproxy.conf|${PREFIX}/etc/tinyproxy.conf|' \
	  ${WRKSRC}/doc/tinyproxy.8
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|stdlib.h|' ${WRKSRC}/src/scanner.c
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/tinyproxy.conf ]; then \
		${CP} -p ${PREFIX}/etc/tinyproxy.conf-dist \
		${PREFIX}/etc/tinyproxy.conf ; \
	fi

.include <bsd.port.post.mk>

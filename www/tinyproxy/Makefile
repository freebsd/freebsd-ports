# New ports collection makefile for:	tinyproxy
# Date created:		01 Jul 1999
# Whom:			Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	tinyproxy
PORTVERSION=	1.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mitsuru@riken.go.jp
COMMENT=	A small, efficient HTTP proxy server

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin --with-config=${PREFIX}/etc/tinyproxy/tinyproxy.conf --program-transform-name=""

MAN8=		tinyproxy.8

.include <bsd.port.pre.mk>

post-patch:
	@cd ${WRKSRC}/doc; f=tinyproxy.8; \
	${MV} $$f $$f.orig; \
	${SED} -e s:/etc/tinyproxy/tinyproxy.conf:${PREFIX}/etc/tinyproxy/tinyproxy.conf: \
	< $$f.orig > $$f
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|stdlib.h|' ${WRKSRC}/src/scanner.c
.endif

.include <bsd.port.post.mk>

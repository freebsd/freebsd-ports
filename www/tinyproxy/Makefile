# New ports collection makefile for:	tinyproxy
# Date created:		01 Jul 1999
# Whom:			Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	tinyproxy
PORTVERSION=	1.4.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mitsuru@riken.go.jp

GNU_CONFIGURE=  yes
USE_GMAKE=	yes
CONFIGURE_ARGS= --bindir=${PREFIX}/sbin --with-config=${PREFIX}/etc/tinyproxy/tinyproxy.conf

MAN8=		tinyproxy.8

post-patch:
	@cd ${WRKSRC}/doc; f=tinyproxy.8; \
	${MV} $$f $$f.orig; \
	${SED} -e s:/etc/tinyproxy/tinyproxy.conf:${PREFIX}/etc/tinyproxy/tinyproxy.conf: \
	< $$f.orig > $$f

post-install:
	${MKDIR} ${PREFIX}/etc/tinyproxy
	${INSTALL_DATA} ${WRKSRC}/doc/tinyproxy.conf ${PREFIX}/etc/tinyproxy/tinyproxy.conf.sample

.include <bsd.port.mk>

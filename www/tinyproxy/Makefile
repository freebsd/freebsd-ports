# New ports collection makefile for:	tinyproxy
# Date created:		01 Jul 1999
# Whom:			Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	tinyproxy
PORTVERSION=	1.3.3
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/tinyproxy/

MAINTAINER=	mitsuru@riken.go.jp

BUILD_DEPENDS=	${LOCALBASE}/lib/libadns.a:${PORTSDIR}/net/adns

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --bindir=${PREFIX}/sbin --with-log-file=/var/log/tinyproxy.log   --with-port=8080 --with-user=nobody --with-adns-include=${LOCALBASE}/include --with-adns-lib=${LOCALBASE}/lib

MAN8=		tinyproxy.8

.include <bsd.port.mk>

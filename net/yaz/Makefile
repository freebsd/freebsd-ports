# New ports collection makefile for:	yaz
# Date created:				16 Sep 2000
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	2.1.8
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Z39.50/SR client and API library

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_ICONV=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-openssl=${OPENSSLBASE} \
		--with-iconv=${LOCALBASE} --with-xml2=${LOCALBASE} \
		--enable-tcpd
INSTALLS_SHLIB=	yes

MAN1=		yaz-asncomp.1 yaz-client.1 yaz-marcdump.1 yaz-iconv.1 zoomsh.1
MAN7=		yaz.7 yaz-log.7
MAN8=		yaz-config.8 yaz-ztest.8

.include <bsd.port.mk>

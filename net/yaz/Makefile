# New ports collection makefile for:	yaz
# Date created:				16 Sep 2000
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	2.0.6
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		xml2.5:${PORTSDIR}/textproc/libxml2

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Z39.50/SR client and API library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		yaz-asncomp.1 yaz-client-ssl.1 yaz-client.1 yaz-marcdump.1 \
		yaz-iconv.1 zoomsh.1
MAN7=		yaz.7
MAN8=		yaz-config.8 yaz-ztest-ssl.8 yaz-ztest.8

.include <bsd.port.mk>

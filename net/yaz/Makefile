# New ports collection makefile for:	yaz
# Date created:				16 Sep 2000
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	1.9.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	demon@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=	yes

MAN1=		yaz-client-ssl.1 yaz-client.1 yaz-config.1 zoomsh.1
MAN7=		yaz.7
MAN8=		yaz-ztest-ssl.8 yaz-ztest.8

.include <bsd.port.mk>

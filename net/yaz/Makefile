# New ports collection makefile for:	yaz
# Date created:				16 Sep 2000
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	4.0.9
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Z39.50/SR client and API library

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

USE_ICONV=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-shared --with-openssl=${OPENSSLBASE} \
		--with-iconv=${LOCALBASE} --with-xml2=${LOCALBASE} \
		--with-xslt=${LOCALBASE} --enable-tcpd
USE_LDCONFIG=	yes

MAN1=		yaz-asncomp.1 yaz-client.1 yaz-iconv.1 yaz-marcdump.1 \
		zoomsh.1 yaz-icu.1 yaz-illclient.1
MAN7=		bib1-attr.7 yaz-log.7 yaz.7
MAN8=		yaz-config.8 yaz-ztest.8

post-configure:
	cd ${WRKSRC}/doc && \
		${REINPLACE_CMD} -e 's,[$$]{datarootdir}/man,${PREFIX}/man,' \
		Makefile

.include <bsd.port.mk>

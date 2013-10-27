# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	yaz
PORTVERSION=	5.0.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Z39.50/SR client and API library

LIB_DEPENDS=	libicuuc.so:${PORTSDIR}/devel/icu

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig iconv
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--enable-shared --with-openssl=${OPENSSLBASE} \
		--with-iconv=${ICONV_PREFIX} --with-xml2=${LOCALBASE} \
		--with-xslt=${LOCALBASE} --with-icu=${LOCALBASE} \
		--enable-tcpd

OPTIONS_DEFINE=	DOCS

post-configure:
	@${REINPLACE_CMD} -e 's,[$$]{datarootdir}/man,${PREFIX}/man,' \
		${WRKSRC}/doc/Makefile

.include <bsd.port.mk>

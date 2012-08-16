# New ports collection makefile for:	yaz
# Date created:				16 Sep 2000
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yaz
PORTVERSION=	4.2.35
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Z39.50/SR client and API library

LIB_DEPENDS=	icuuc:${PORTSDIR}/devel/icu

USE_ICONV=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_GNOME=	libxml2 libxslt gnomehack
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS+=--enable-shared --with-openssl=${OPENSSLBASE} \
		--with-iconv=${LOCALBASE} --with-xml2=${LOCALBASE} \
		--with-xslt=${LOCALBASE} --with-icu=${LOCALBASE} \
		--enable-tcpd

MAN1=		yaz-asncomp.1 yaz-client.1 yaz-config.1 yaz-iconv.1 \
		yaz-json-parse.1 yaz-marcdump.1 \
		zoomsh.1 yaz-icu.1 yaz-illclient.1 yaz-url.1
MAN7=		bib1-attr.7 yaz-log.7 yaz.7
MAN8=		yaz-ztest.8

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-doc__Makefile.in
.endif

post-configure:
	${REINPLACE_CMD} -e 's,[$$]{datarootdir}/man,${PREFIX}/man,' \
		${WRKSRC}/doc/Makefile

.include <bsd.port.mk>

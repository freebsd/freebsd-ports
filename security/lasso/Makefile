# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	lasso
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://dev.entrouvert.org/releases/lasso/

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Free Liberty Alliance Implementation

LICENSE=	GPLv2

BUILD_DEPENDS=	xmlsec1:security/xmlsec1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cpe libtool pathfix pkgconfig
CPE_VENDOR=	entrouvert
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-java --with-zlib
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PERL PHP PYTHON DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--enable-perl
PLIST_SUB+=	PERL=""
USES+=		perl5
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=	--enable-php5 \
		--with-php5-config="${LOCALBASE}/bin/php-config"
LDFLAGS+=	-L${LOCALBASE}/lib
LIB_DEPENDS+=	libexpat.so:textproc/expat2
PLIST_SUB+=	PHP5=""
USES+=		php:build
.else
CONFIGURE_ARGS+=	--disable-php5
PLIST_SUB+=	PHP5="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=	PYTHON=""
USES+=		python
.else
USES+=		python:build
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,(xmlsec1-openssl >= 1\.2\.6) openssl,\1,' \
		${CONFIGURE_WRKSRC}/configure

.include <bsd.port.mk>

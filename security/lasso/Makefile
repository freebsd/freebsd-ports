# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	lasso
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://labs.libre-entreprise.org/frs/download.php/594/

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Free Liberty Alliance Implementation

BROKEN=		Fails to build

RUN_DEPENDS=	xmlsec1:${PORTSDIR}/security/xmlsec1
BUILD_DEPENDS:=	${RUN_DEPENDS}

CONFIGURE_ARGS+=	--disable-java --disable-php4 --with-zlib
GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_GNOME=	gnomehack glib20 libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

OPTIONS_DEFINE=	PERL PHP PYTHON DOCS

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MPERL)
CONFIGURE_ARGS+=	--enable-perl
PLIST_SUB+=	WITH_PERL=""
USES+=		perl5
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if !empty(PORT_OPTIONS:MPHP)
CONFIGURE_ARGS+=	--enable-php5 \
		--with-php5-config="${LOCALBASE}/bin/php-config"
LDFLAGS+=	"-L${LOCALBASE}/lib"
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2
PLIST_SUB+=	WITH_PHP5=""
USE_PHP=	yes
USE_PHP_BUILD=	yes
.else
CONFIGURE_ARGS+=	--disable-php5
PLIST_SUB+=	WITH_PHP5="@comment "
.endif

.if !empty(PORT_OPTIONS:MPYTHON)
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=	WITH_PYTHON=""
USES+=		python
USE_PYTHON=	yes
.else
USES+=		python:build
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

post-install:
	${RM} -f ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal.pod

.include <bsd.port.mk>

PORTNAME=	modsecurity
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.4
PORTREVISION=	2
CATEGORIES=	security www
MASTER_SITES=	https://github.com/SpiderLabs/ModSecurity/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	3

MAINTAINER=	marius.halden@modirum.com
COMMENT=	Intrusion detection and prevention engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libyajl.so:devel/yajl \
		libmaxminddb.so:net/libmaxminddb

USES=		compiler:c++11-lang gmake gnome libtool pkgconfig:build
USE_GNOME=	libxml2
# GCC because of https://github.com/SpiderLabs/ModSecurity/issues/1411
USE_GCC=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lmdb --without-ssdeep --without-lua

PLIST_SUB=	SHLIBVER=${DISTVERSION}

ETCDIR=		${PREFIX}/etc/modsecurity

CONFLICTS_INSTALL=	ap??-mod_security mod_security3

INSTALL_TARGET=		install-strip

post-install:
	@${MKDIR}	${STAGEDIR}${ETCDIR}
	${INSTALL_DATA}	${WRKSRC}/modsecurity.conf-recommended \
		${STAGEDIR}${ETCDIR}/modsecurity.conf.sample
	${INSTALL_DATA} ${WRKSRC}/unicode.mapping \
		${STAGEDIR}${ETCDIR}/unicode.mapping

.include <bsd.port.mk>

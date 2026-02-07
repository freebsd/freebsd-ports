PORTNAME=	modsecurity
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.14
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	https://github.com/owasp-modsecurity/ModSecurity/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	3

MAINTAINER=	marius.halden@modirum.com
COMMENT=	Intrusion detection and prevention engine
WWW=		https://www.modsecurity.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libyajl.so:devel/yajl \
		libmaxminddb.so:net/libmaxminddb

USES=		cpe gmake gnome libtool pkgconfig:build

CPE_VENDOR=	trustwave

USE_GNOME=	libxml2
# GCC because of https://github.com/SpiderLabs/ModSecurity/issues/1411
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lmdb --without-ssdeep --without-lua

INSTALL_TARGET=		install-strip

CONFLICTS_INSTALL=	ap??-mod_security mod_security3

ETCDIR=		${PREFIX}/etc/modsecurity

PLIST_SUB=	SHLIBVER=${DISTVERSION}

post-install:
	@${MKDIR}	${STAGEDIR}${ETCDIR}
	${INSTALL_DATA}	${WRKSRC}/modsecurity.conf-recommended \
		${STAGEDIR}${ETCDIR}/modsecurity.conf.sample
	${INSTALL_DATA} ${WRKSRC}/unicode.mapping \
		${STAGEDIR}${ETCDIR}/unicode.mapping

.include <bsd.port.mk>

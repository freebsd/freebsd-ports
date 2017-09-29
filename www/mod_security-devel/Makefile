# $FreeBSD$

PORTNAME=	mod_security-devel
PORTVERSION=	3.0.0.g2017080200
PORTREVISION=	1
CATEGORIES=	www security

MAINTAINER=	marius.halden@modirum.com
COMMENT=	Intrusion detection and prevention engine

LICENSE=	APACHE20

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libyajl.so:devel/yajl \
		libGeoIP.so:net/GeoIP

USES=		gmake autoreconf libtool pkgconfig:build
USE_GNOME=	libxml2
# GCC because of https://github.com/SpiderLabs/ModSecurity/issues/1411
USE_GCC=	6+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SpiderLabs
GH_PROJECT=	ModSecurity
GH_TAGNAME=	0508395

GH_TUPLE+=	SpiderLabs:secrules-language-tests:add8f63:secrules_language_tests/test/test-cases/secrules-language-tests
GH_TUPLE+=	client9:libinjection:da027ab:libinjection/others/libinjection
GH_TUPLE+=	SpiderLabs:ModSecurity-Python-bindings:bc625d5:modsecurity_python_bindings/bindings/python

ETCDIR=		${PREFIX}/etc/modsecurity

post-install:
	@${MKDIR}	${STAGEDIR}${ETCDIR}
	${INSTALL_DATA}	${WRKSRC}/modsecurity.conf-recommended \
		${STAGEDIR}${ETCDIR}/modsecurity.conf.sample

.include <bsd.port.mk>

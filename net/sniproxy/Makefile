PORTNAME=	sniproxy
DISTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Proxy that routes based on TLS server name extension
WWW=		https://github.com/dlundquist/sniproxy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libev.so:devel/libev \
		libpcre2-8.so:devel/pcre2 \
		libudns.so:dns/udns

USES=		autoreconf localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	dlundquist
USE_LDCONFIG=	yes
USE_RC_SUBR=	sniproxy
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-dns

SUB_FILES=	pkg-message
PLIST_FILES=	"@sample etc/sniproxy.conf.sample" \
		sbin/sniproxy \
		share/man/man5/sniproxy.conf.5.gz \
		share/man/man8/sniproxy.8.gz

post-install::
	${INSTALL_DATA} ${WRKSRC}/sniproxy.conf ${STAGEDIR}${PREFIX}/etc/sniproxy.conf.sample

.include <bsd.port.mk>

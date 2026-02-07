PORTNAME=	sniproxy
DISTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	net

PATCH_SITES=	https://github.com/dlundquist/sniproxy/commit/
PATCHFILES=	62e621f050f79eb78598b1296a089ef88a19ea91.diff:-p1 \
		0e556bf0b9151e65575b3980b72f34331e5b6ab4.diff:-p1 \
		7fdd86c054a21f7ac62343010de20f28645b14d2.diff:-p1 \
		85e980261b9dfc0172fbc38f7bb24b291e859cee.diff:-p1 \
		2d9965388712faa6ef74f7229f38e3a177904bae.diff:-p1

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Proxy that routes based on TLS server name extension
WWW=		https://github.com/dlundquist/sniproxy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libev.so:devel/libev \
		libpcre2-8.so:devel/pcre2 \
		libudns.so:dns/udns

USES=		autoreconf localbase pkgconfig

SUB_FILES=	pkg-message
USE_RC_SUBR=	sniproxy

USE_GITHUB=	yes
GH_ACCOUNT=	dlundquist

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	share/man/man5/sniproxy.conf.5.gz \
		share/man/man8/sniproxy.8.gz \
		sbin/sniproxy \
		"@sample etc/sniproxy.conf.sample"

post-patch:
	@${REINPLACE_CMD} -e 's|/var/tmp/|/var/run/|' ${WRKSRC}/${PORTNAME}.conf

post-install::
	${INSTALL_DATA} ${WRKSRC}/sniproxy.conf ${STAGEDIR}${PREFIX}/etc/sniproxy.conf.sample

.include <bsd.port.mk>

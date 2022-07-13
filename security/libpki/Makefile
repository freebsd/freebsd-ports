PORTNAME=	libpki
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
CATEGORIES=	security

PATCH_SITES=	https://github.com/openca/libpki/commit/
PATCHFILES=	d7617046e9da97473a140c02582fa571f6359ae3.patch:-p1

MAINTAINER=	bruno@ruomad.net
COMMENT=	OpenCA PKI library (libpki) and tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gnome libtool ssl
USE_GITHUB=	yes
GH_ACCOUNT=	openca
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-dns \
		--disable-iphone \
		--disable-ldap \
		--disable-mysql \
		--disable-pg
INSTALL_TARGET=	install-strip

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/etc/pki.conf ${STAGEDIR}${PREFIX}/etc/pki.conf.sample; \
	for f in $$(find ${STAGEDIR}${PREFIX}/etc/libpki -type f); do \
		${MV} $$f $$f.sample; \
	done; \
	${RM} -rf ${STAGEDIR}${PREFIX}/include/internal

.include <bsd.port.mk>

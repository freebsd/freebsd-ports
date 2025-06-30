PORTNAME=	libpki
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
PORTREVISION=	7
CATEGORIES=	security

PATCH_SITES=	https://github.com/openca/libpki/commit/
PATCHFILES=	d7617046e9da97473a140c02582fa571f6359ae3.patch:-p1 \
		9c4865ad476a75c34d89e0bd663c280f544590c0.patch:-p1

MAINTAINER=	bruno@ruomad.net
COMMENT=	OpenCA PKI library (libpki) and tools
WWW=		https://www.openca.org/projects/libpki

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gnome libtool ssl
USE_GITHUB=	yes
GH_ACCOUNT=	openca

USE_GNOME=	libxml2
USE_LDCONFIG=	yes

PATCH_STRIP= 	-p0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-iphone

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DNS LDAP MYSQL PGSQL

DNS_DESC=	"Enable DNS support"
LDAP_DESC=	"Enable LDAP support"
MYSQL_DESC=	"Enable MySQL support"
PGSQL_DESC=	"Enable PostgreSQL support"

DNS_CONFIGURE_ENABLE=	dns
LDAP_USES=		ldap
LDAP_CONFIGURE_ENABLE=	ldap
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ENABLE=	mysql
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	pg

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/libpki/etc; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/libpki/etc/libpki; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/libpki/etc/libpki/hsm.d; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/libpki/etc/libpki/profile.d; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/libpki/etc/libpki/store.d; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/libpki/etc/libpki/token.d; \
	${MV} ${STAGEDIR}${PREFIX}/etc/pki.conf ${STAGEDIR}${PREFIX}/share/libpki/etc/pki.conf.sample; \
	cd ${STAGEDIR}${PREFIX}/etc/libpki; \
	for f in $$(find * -type f); do \
		${MV} ${STAGEDIR}${PREFIX}/etc/libpki/$$f ${STAGEDIR}${PREFIX}/share/libpki/etc/libpki/$$f.sample; \
	done; \
	${RM} -rf ${STAGEDIR}${PREFIX}/include/internal

.include <bsd.port.mk>

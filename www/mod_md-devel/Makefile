# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_md
PORTVERSION=	1.1.16
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Early experience LetsEncrypt module for Apache httpd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips=		fails to compile: md_json.c:29: expected [error|warning|ignored] after pragma GCC diagnostic
BROKEN_mips64=		fails to compile: md_json.c:29: expected [error|warning|ignored] after pragma GCC diagnostic

LIB_DEPENDS=	libaprutil-1.so:devel/apr1 \
		libcurl.so:ftp/curl \
		libjansson.so:devel/jansson

USES=		apache:2.4+ autoreconf libtool ssl
USE_GITHUB=	yes

INSTALL_TARGET=	install-strip

GH_ACCOUNT=	icing
GH_PROJECT=	mod_md

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} \
		--with-jansson=${LOCALBASE} \
		--without-boulder

SUB_FILES=	999_mod_md.conf pkg-message
DOCSDIR=	share/doc/mod_md
PORTDOCS=	README README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${RM} ${STAGEDIR}${PREFIX}/share/doc/mod_md/LICENSE
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/999_mod_md.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d/999_mod_md.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_md.so.0.0.0 \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_manageddomain.so.0.0.0
	${RM} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_md.so
	(cd ${STAGEDIR}${PREFIX}/${APACHEMODDIR} && \
		${LN} mod_manageddomain.so.0.0.0 mod_manageddomain.so)

.include <bsd.port.mk>

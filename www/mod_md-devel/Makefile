# Created by: Bernard Spil <brnrd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_md-devel
PORTVERSION=	0.9.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Early experience LetsEncrypt module for Apache httpd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjansson.so:devel/jansson

USES=		autoreconf libtool ssl
USE_GITHUB=	yes
USE_APACHE=	24+

GH_ACCOUNT=	icing
GH_PROJECT=	mod_md

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=ext-
CONFIGURE_ENV=	CONFIG_SHELL=/bin/sh

MODULENAME=	${GH_PROJECT}

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include

DOCSDIR=	share/doc/mod_md
PORTDOCS=	README README.md
PLIST_FILES=	${APACHEMODDIR}/mod_md.so.0.0.0 \
		${APACHEMODDIR}/mod_md.so \
		bin/a2md

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100085 && ${SSL_DEFAULT} == base
IGNORE=		port requires OpenSSL 1.0.2 or later, set DEFAULT_VERSIONS+= ssl=openssl
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	${INSTALL} ${WRKSRC}/src/a2md ${STAGEDIR}${PREFIX}/bin/a2md
	${RM} ${STAGEDIR}${PREFIX}/share/doc/mod_md/LICENSE
	${RM} ${STAGEDIR}${PREFIX}/bin/ext-a2md

.include <bsd.port.post.mk>

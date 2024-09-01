PORTNAME=	xmlsec1
DISTVERSION=	1.3.5
CATEGORIES=	security
MASTER_SITES=	https://github.com/lsh123/xmlsec/releases/download/xmlsec_${DISTVERSION:S,.,_,g}/ \
		https://www.aleksey.com/xmlsec/download/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XML Security Library
WWW=		https://www.aleksey.com/xmlsec/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Copyright

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gmake gnome libtool localbase pathfix pkgconfig
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PORTDOCS=	*
PLIST_SUB=	DISTVERSION=${DISTVERSION}

CONFIGURE_ARGS=	--disable-static

OPTIONS_DEFINE=		DOCS
OPTIONS_MULTI=		SSL
OPTIONS_MULTI_SSL=	GNUTLS NSS OPENSSL
OPTIONS_DEFAULT=	OPENSSL NSS
OPTIONS_SUB=		yes

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gcrypt gnutls

NSS_LIB_DEPENDS=	libnspr4.so:devel/nspr \
			libnss3.so:security/nss
NSS_CONFIGURE_WITH=	nspr nss

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_OFF=	--without-openssl
OPENSSL_CONFIGURE_ON=	--with-openssl="${OPENSSLBASE}"

post-patch:
	@${REINPLACE_CMD} -e 's/(CP) -ru/(CP) -r/' \
		-e 's/(CP) -u/(CP)/' \
		${PATCH_WRKSRC}/docs/Makefile.am \
		${PATCH_WRKSRC}/docs/Makefile.in \
		${PATCH_WRKSRC}/docs/api/Makefile.am \
		${PATCH_WRKSRC}/docs/api/Makefile.in \
		${PATCH_WRKSRC}/man/Makefile.am \
		${PATCH_WRKSRC}/man/Makefile.in

post-patch-GNUTLS-on:
# Don't rely on broken autodetection
	@${REINPLACE_CMD} -e '/^GNUTLS_FOUND/s/no/yes/' \
		-e '/^GNUTLS_LIBS=/s,"","-L${LOCALBASE}/lib -lgnutls",' \
		${PATCH_WRKSRC}/${CONFIGURE_SCRIPT}

post-patch-NSS-on:
	@${REINPLACE_CMD} -e 's/mozilla-nss/nss/' \
		-e 's/mozilla-nspr/nspr/' ${PATCH_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,^\(xmlsec1_LDADD = \)\\$$,\1 -L${LOCALBASE}/lib -lpthread\\,' \
		${PATCH_WRKSRC}/apps/Makefile.in

post-install:
	${RM} -r ${STAGEDIR}${DOCSDIR}/css

.include <bsd.port.mk>

# Created by: Jim Geovedi <jim@corebsd.or.id>
# $FreeBSD$

PORTNAME=	xmlsec1
PORTVERSION=	1.2.23
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/ \
		ftp://ftp.aleksey.com/pub/xmlsec/releases/ \
		ftp://ftp.xmlsoft.org/xmlsec/releases/ \
		ftp://ftp.rpmfind.net/pub/XML/xmlsec/releases/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XML Security Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Copyright

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libltdl.so:devel/libltdl

USES=		libtool localbase pathfix pkgconfig ssl
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl="${OPENSSLBASE}" \
		--with-gcrypt="${LOCALBASE}"
MAKE_ENV=	ABS_BUILDDIR=${WRKSRC} TMPFOLDER=${WRKSRC}
INSTALL_TARGET=	install-strip
PORTDOCS= api authors.html bugs.html c14n.html documentation.html	\
	download.html faq.html favicon.ico images/bart.gif		\
	images/libxml2-logo.png images/libxslt-logo.png			\
	images/logo.gif images/openssl-logo.png				\
	images/xmlsec-logo.gif index.html news.html related.html	\
	xmldsig-verifier.html xmldsig.html xmlenc.html			\
	xmlsec-man.html

OPTIONS_DEFINE=	DOCS GNUTLS NSS
OPTIONS_SUB=	yes

DOCS_MAKE_ENV=		DOCS=docs
GNUTLS_DESC=		Enable GNUTLS support
GNUTLS_CONFIGURE_ON=	--with-gnutls="${LOCALBASE}"
GNUTLS_CONFIGURE_OFF=	--without-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
NSS_DESC=		Enable Mozilla's NSS support
NSS_CONFIGURE_ON=	--with-nss="${LOCALBASE}" \
			--with-nspr="${LOCALBASE}"
NSS_CONFIGURE_OFF=	--without-nss \
			--without-nspr
NSS_LIB_DEPENDS=	libnss3.so:security/nss \
			libnspr4.so:devel/nspr \
			libplds4.so:devel/nspr \
			libplc4.so:devel/nspr

.if !defined(.PARSEDIR)
MAKE_ARGS+=	-EABS_BUILDDIR
.endif

post-patch-GNUTLS-on:
# Don't rely on broken autodetection
	@${REINPLACE_CMD} -e '/^GNUTLS_FOUND/s/no/yes/' \
	    -e '/^GNUTLS_LIBS=/s,"","-L${LOCALBASE}/lib -lgnutls",' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch-NSS-on:
# Makeing the xmlsec1 executable multi-threaded to let load -lnss,
# when needed.
	@${REINPLACE_CMD} -e 's,^\(xmlsec1_LDADD = \)\\$$,\1 -L${LOCALBASE}/lib -lpthread\\,' \
		${WRKSRC}/apps/Makefile.in

.include <bsd.port.mk>

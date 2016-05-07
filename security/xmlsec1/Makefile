# Created by: Jim Geovedi <jim@corebsd.or.id>
# $FreeBSD$

PORTNAME=	xmlsec1
PORTVERSION=	1.2.22
CATEGORIES=	security
MASTER_SITES=	http://www.aleksey.com/xmlsec/download/ \
		ftp://ftp.aleksey.com/pub/xmlsec/releases/ \
		ftp://ftp.xmlsoft.org/xmlsec/releases/ \
		ftp://ftp.rpmfind.net/pub/XML/xmlsec/releases/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	XML Security Library

LIB_DEPENDS=	libltdl.so:devel/libltdl

OPTIONS_DEFINE=	DOCS GNUTLS NSS
OPTIONS_SUB=	yes
GNUTLS_DESC=		Enable GNUTLS support
GNUTLS_CONFIGURE_WITH=	gnutls="${LOCALBASE}"
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
NSS_DESC=		Enable Mozilla's NSS support
NSS_CONFIGURE_WITH=	nss="${LOCALBASE}" nspr="${LOCALBASE}"
NSS_LIB_DEPENDS=	libnss3.so:security/nss

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_OPENSSL=	yes
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	ABS_BUILDDIR=${WRKSRC} TMPFOLDER=${WRKSRC} DOCS=docs
CONFIGURE_ARGS+=--with-openssl="${OPENSSLBASE}"

.if !defined(.PARSEDIR)
MAKE_ARGS+=	-EABS_BUILDDIR
.endif

.include <bsd.port.options.mk>

# avoid --without-opt=PATH constructs
CONFIGURE_ARGS:=${CONFIGURE_ARGS:C/without-([a-z]*)=.*/without-\1/}

post-patch:
	@${REINPLACE_CMD} -e 's|src apps man docs|src apps man \$${DOCS}|g' \
	    -e 's|^confexecdir =.*$$|confexecdir = \$$(sysconfdir)|g' \
	    -e 's|/tmp/\*\.log|${WRKSRC}/*.log|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
	    -e '/^XMLSEC_SHLIBSFX="/s|"[^"]*"|".so"|' \
	    -e 's|openssl_exlibs=-ldl|openssl_exlibs=|' \
	    -e 's|-ldl"|"|' \
	    -e 's,with_nss/include,with_nss/include/nss/nss,' \
	    -e 's,with_nss/lib,with_nss/lib/nss,g' \
	    -e 's,\(CPPFLAGS="\$$NSS_CFLAGS\),\1 $$NSPR_CFLAGS,' \
	    -e '/XMLSEC_CRYPTO_LIST=.*openssl/s,$$,\; CPPFLAGS="$$CPPFLAGS $$OPENSSL_CFLAGS",' \
	    -e 's,\(-lplc4\)",\1 -lpthread",' \
	    -e '/ test /s, == , = ,' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} \
	    -e 's,total_time.*/ 1000),total_time*1000/CLOCKS_PER_SEC,' \
		${WRKSRC}/apps/xmlsec.c
	@${REINPLACE_CMD} -e 's,\\\\\\,\\,g' ${WRKSRC}/*.pc.in
.if ${PORT_OPTIONS:MGNUTLS}
# Don't rely on broken autodetection
	@${REINPLACE_CMD} -e '/^GNUTLS_FOUND/s/no/yes/' \
	    -e '/^GNUTLS_LIBS=/s,"","-L${LOCALBASE}/lib -lgnutls",' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.if ${PORT_OPTIONS:MNSS}
# Makeing the xmlsec1 executable multi-threaded to let load -lnss,
# when needed.
	@${REINPLACE_CMD} -e 's,^\(xmlsec1_LDADD = \)\\$$,\1 -L${LOCALBASE}/lib -lpthread\\,' \
		${WRKSRC}/apps/Makefile.in
.endif

.include <bsd.port.mk>

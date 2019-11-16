# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxslt
DISTVERSION=	1.1.34
CATEGORIES?=	textproc gnome
MASTER_SITES=	http://xmlsoft.org/sources/ \
		https://mirror.umd.edu/xbmc/build-deps/sources/
DIST_SUBDIR=	gnome2

MAINTAINER?=	desktop@FreeBSD.org
COMMENT?=	The XSLT C library for GNOME

.if !defined(REFERENCE_PORT)

USES+=		cpe gmake gnome localbase libtool pathfix
CPE_VENDOR=	xmlsoft
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_GNOME?=	libxml2
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--without-python

LICENSE=	MIT

.if defined(MASTERDIR)
_SLAVE_PORT=	yes
.else

OPTIONS_DEFINE=	MEM_DEBUG CRYPTO
OPTIONS_DEFAULT=CRYPTO
MEM_DEBUG_DESC=	Enable memory debugging
CRYPTO_DESC=	Enable crypto support for exslt
.endif

MEM_DEBUG_CONFIGURE_ON=	--with-mem-debug
CRYPTO_CONFIGURE_WITH=	crypto
CRYPTO_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|[$$](bindir)/xsltproc|../xsltproc/xsltproc|g ; \
		s|[$$](bindir)/xmllint|../xmllint/xmllint|g' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>

.endif

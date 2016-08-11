# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxslt
PORTVERSION=	1.1.29
PORTREVISION?=	0
CATEGORIES?=	textproc gnome
MASTER_SITES=	ftp://xmlsoft.org/libxml2/ \
		http://xmlsoft.org/sources/ \
		ftp://gd.tuwien.ac.at/pub/libxml/
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	The XSLT C library for GNOME

.if !defined(REFERENCE_PORT)

USES+=		cpe gmake libtool pathfix
CPE_VENDOR=	xmlsoft
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_GNOME?=	libxml2
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--without-python
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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

.if !defined(MASTERDIR)
post-stage:
	${LN} -s libxslt.so.1 ${STAGEDIR}${PREFIX}/lib/libxslt.so.2
	${LN} -s libexslt.so.0 ${STAGEDIR}${PREFIX}/lib/libexslt.so.8
.endif

.include <bsd.port.mk>

.endif

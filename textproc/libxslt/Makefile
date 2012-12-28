# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxslt
PORTVERSION=	1.1.28
PORTREVISION?=	0
CATEGORIES?=	textproc gnome
MASTER_SITES=	ftp://gd.tuwien.ac.at/pub/libxml/ \
		ftp://xmlsoft.org/libxml2/
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	The XSLT C library for GNOME

.if !defined(REFERENCE_PORT)

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME?=	gnomehack libxml2
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--without-python
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LICENSE=	MIT

.if defined(MASTERDIR)
_SLAVE_PORT=	yes
.else
MAN3=		libexslt.3 libxslt.3
MAN1=		xsltproc.1

OPTIONS_DEFINE=	MEM_DEBUG CRYPTO
OPTIONS_DEFAULT=CRYPTO
MEM_DEBUG_DESC=	Enable memory debugging
CRYPTO_DESC=	Enable crypto support for exslt
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMEM_DEBUG}
CONFIGURE_ARGS+=	--with-mem-debug
.endif

.if ${PORT_OPTIONS:MCRYPTO}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
.else
CONFIGURE_ARGS+=--without-crypto
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|[$$](bindir)/xsltproc|../xsltproc/xsltproc|g ; \
		s|[$$](bindir)/xmllint|../xmllint/xmllint|g' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>

.endif

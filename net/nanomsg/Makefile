# $FreeBSD$

PORTNAME=			nanomsg
DISTVERSION=			0.8-beta
CATEGORIES=			net

MAINTAINER=			crest@bultmann.eu
COMMENT=			Socket library that provides several common communication patterns

LICENSE=			MIT
LICENSE_FILE=			${WRKSRC}/COPYING

USE_GITHUB=			yes
GH_ACCOUNT=			nanomsg

USES=				autoreconf libtool pathfix
USE_LDCONFIG=			yes
GNU_CONFIGURE=			yes
INSTALL_TARGET=			install-strip

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=		--disable-silent-rules
.endif
CONFIGURE_ARGS+=		--datadir=${PREFIX}/libdata

OPTIONS_DEFINE=			DOCS MANPAGES
OPTIONS_DEFAULT=		MANPAGES
OPTIONS_SUB=			yes

DOCS_DESC=			Build and/or install HTML documentation

MANPAGES_BUILD_DEPENDS+=	asciidoc:textproc/asciidoc \
				xmlto:textproc/xmlto

.include <bsd.port.options.mk>

# Avoid duplication
.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
CONFIGURE_ARGS+=	--enable-doc
BUILD_DEPENDS+=		asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
.endif

post-extract:
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(datadir)/pkgconfig|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>

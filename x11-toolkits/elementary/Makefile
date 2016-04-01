# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elementary
PORTVERSION=	1.16.1
CATEGORIES=	x11-toolkits enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PORTNAME}/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Simple widget toolkit using EFL

LICENSE=	LGPL21

LIB_DEPENDS=	libefl.so:devel/efl

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		compiler:c11 gmake libtool lua pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R} PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
LDFLAGS+=		-L${LOCALBASE}/lib
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
CONFIGURE_ARGS+=	--enable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|= \$$(pkgdatadir)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: signal 10
.endif

.include <bsd.port.mk>

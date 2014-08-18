# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/lang/vala/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	vala
PORTVERSION=	0.24.0
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LICENSE=	LGPL21

USES=		bison gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

VALA_VER=	${PORTVERSION:R}

PLIST_SUB=	VERSION=${VALA_VER}

.if defined(VALA_SLAVE)
LIB_DEPENDS+=	libvala-${VALA_VER}.so:${PORTSDIR}/lang/vala
CONFIGURE_ARGS+=--enable-vapigen
BUILD_DEPENDS+=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS+=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
.else
CONFIGURE_ARGS+=--disable-vapigen

PLIST_SUB=	VERSION=${VALA_VER}
.endif

.if defined(VALA_SLAVE)
LIB_DEPENDS+=	libvala-${VALA_VER}.so:${PORTSDIR}/lang/vala
CONFIGURE_ARGS+=--enable-vapigen
BUILD_DEPENDS+=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS+=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
.else
CONFIGURE_ARGS+=--disable-vapigen
.endif

post-patch:
# We cheat here, because vala records vapigen related stuff in its .pc file
# This makes vapigen work again, although it might get weird when
# vala-vapigen isn't installed.
	@${REINPLACE_CMD} -e 's|@vapigen_decl@|vapigen=$${bindir}/vapigen-${VALA_VER}|g' \
		-e 's|@gen_introspect_decl@|gen_introspect=$${libdir}/vala-${VALA_VER}/gen-introspect-${VALA_VER}|g' \
		-e 's|@vala_gen_introspect_decl@|vala_gen_introspect=$${bindir}/vala-gen-introspect-${VALA_VER}|g' \
		${WRKSRC}/libvala.pc.in
#	@${REINPLACE_CMD} -e 's|cp $$< $$@|cp libvala.pc libvala-${VALA_VER}.pc|g' \
#		${WRKSRC}/Makefile.in

.if defined(VALA_SLAVE)
pre-build:
	@cd ${WRKSRC} && ${GMAKE} version.h
	@cd ${WRKSRC}/gobject-introspection && ${GMAKE} libgidl.la && \
		${GMAKE} gen-introspect

post-install:
	@cd ${WRKSRC}/gobject-introspection && DESTDIR=${STAGEDIR} ${GMAKE} install
	@${INSTALL_MAN} ${WRKSRC}/doc/vapigen.1 ${WRKSRC}/doc/vala-gen-introspect.1 \
		 ${STAGEDIR}${PREFIX}/man/man1/
.else
post-install:
	${LN} -fs ${PREFIX}/libdata/pkgconfig/libvala-${VALA_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/vala-1.0.pc
.endif

.include <bsd.port.mk>

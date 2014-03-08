# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/lang/vala/Makefile 19019 2014-03-08 14:51:46Z kwm $

PORTNAME=	vala
PORTVERSION=	0.20.1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LICENSE=	LGPL21

USES=		bison gettext gmake libtool pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	glib20 gnomeprefix libxslt introspection:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

VALA_VER=	${PORTVERSION:R}

PLIST_SUB=	VERSION=${VALA_VER}

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
	@${REINPLACE_CMD} -e 's|cp $$< $$@|cp libvala.pc libvala-${VALA_VER}.pc|g' \
		${WRKSRC}/Makefile.in

.if defined(VALA_SLAVE)
pre-build:
	@cd ${WRKSRC} && ${GMAKE} version.h
	@cd ${WRKSRC}/gobject-introspection && ${MAKE_CMD} libgidl.la && \
		${MAKE_CMD} gen-introspect
	@cd ${WRKSRC}/vapigen && ${MAKE_CMD} all

post-install:
	@cd ${WRKSRC}/gobject-introspection && DESTDIR=${STAGEDIR} ${GMAKE} install
	${INSTALL_MAN} ${WRKSRC}/doc/vapigen.1 ${WRKSRC}/doc/vala-gen-introspect.1 \
		 ${STAGEDIR}${PREFIX}/man/man1/
.else
post-install:
	${LN} -fs ${PREFIX}/libdata/pkgconfig/libvala-${VALA_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/vala-1.0.pc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*
.endif

.include <bsd.port.mk>

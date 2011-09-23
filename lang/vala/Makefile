# New ports collection makefile for:	vala
# Date created:		2007-07-09
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/lang/vala/Makefile,v 1.55 2011/06/02 12:10:13 kwm Exp $
#

PORTNAME=	vala
PORTVERSION=	0.12.1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_XZ=		yes
USE_GNOME=	gnomehack glib20 gnomeprefix libxslt
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib
USE_BISON=	build
USE_LDCONFIG=	yes

MAN1?=		valac.1 valac-0.12.1

PLIST_SUB=	VERSION=0.12

.include <bsd.port.pre.mk>

.if defined(VALA_SLAVE)
LIB_DEPENDS+=	vala-0.12.0:${PORTSDIR}/lang/vala
CONFIGURE_ARGS+=--enable-vapigen
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
MAN1=		vala-gen-introspect.1 vapigen.1
.else
CONFIGURE_ARGS+=--disable-vapigen
.endif

post-patch:
# We cheat here, because vala records vapigen related stuff in its .pc file
# This makes the vapigen work again, although it might get weird when
# vala-vapigen isn't installed.
	@${REINPLACE_CMD} -e 's|@vapigen_decl@|vapigen=$${bindir}/vapigen-0.12|g' \
		-e 's|@gen_introspect_decl@|gen_introspect=$${libdir}/vala-0.12/gen-introspect-0.12|g' \
		-e 's|@vala_gen_introspect_decl@|vala_gen_introspect=$${bindir}/vala-gen-introspect-0.12|g' \
		${WRKSRC}/libvala.pc.in
	@${REINPLACE_CMD} -e 's|cp $$< $$@|cp libvala.pc libvala-0.12.pc|g' \
		${WRKSRC}/Makefile.in

.if defined(VALA_SLAVE)
pre-build:
	@cd ${WRKSRC} && ${GMAKE} version.h
	@cd ${WRKSRC}/gobject-introspection && ${GMAKE} libgidl.la && \
		${GMAKE} gen-introspect

post-install:
	@cd ${WRKSRC}/gobject-introspection && ${GMAKE} install
	@${INSTALL_MAN} ${WRKSRC}/doc/vapigen.1 ${WRKSRC}/doc/vala-gen-introspect.1 \
		 ${PREFIX}/man/man1/
.else
# want to see what will fail.
post-install:
	${LN} -fs ${PREFIX}/libdata/pkgconfig/libvala-0.12.pc \
		${PREFIX}/libdata/pkgconfig/vala-1.0.pc
.endif

.include <bsd.port.post.mk>

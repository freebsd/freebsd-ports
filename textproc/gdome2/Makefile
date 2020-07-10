# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gdome2
PORTVERSION=	0.8.1
PORTREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	http://gdome2.cs.unibo.it/tarball/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome DOM Engine

USES=		gnome libtool pathfix pkgconfig
USE_GNOME=	glib20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${LOCALBASE}/bin/pkg-config glib-2.0"
CFLAGS+=	-fcommon
CPPFLAGS+=	-I${LOCALBASE}/include
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${FIND} ${WRKSRC} -type f -and \
		'(' -name '*.[ch]' -or -name '*.xml' ')' | \
		${XARGS} ${REINPLACE_CMD} -e ' \
		 s,<parser\.h>,<libxml/parser.h>,; \
		 s,<hash\.h>,<libxml/hash.h>,; \
		 s,<xmlmemory\.h>,<libxml/xmlmemory.h>,; \
		 s,<tree\.h>,<libxml/tree.h>,; \
		 s,<xmlerror\.h>,<libxml/xmlerror.h>,; \
		 s,<xmlIO\.h>,<libxml/xmlIO.h>,; \
		 s,<parserInternals\.h>,<libxml/parserInternals.h>,; \
		 s,<entities\.h>,<libxml/entities.h>,'

post-patch-DOCS-on:
	@${REINPLACE_CMD} -E -e \
		's,^(HTML_DIR *= *).*,\1\$$(DESTDIR)$$(prefix)/share/doc,' \
		${WRKSRC}/gtk-doc/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} '/gtk-doc/d' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdome.so

.include <bsd.port.mk>

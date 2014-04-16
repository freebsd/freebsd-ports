# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gdome2
PORTVERSION=	0.8.1
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://gdome2.cs.unibo.it/tarball/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome DOM Engine

USES=		pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${LOCALBASE}/bin/pkg-config glib-2.0"
CPPFLAGS+=	-I${LOCALBASE}/include
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E -e \
		's,^(HTML_DIR *= *).*,\1\$$(DESTDIR)$$(prefix)/share/doc,' \
		${WRKSRC}/gtk-doc/Makefile.in
.else
	@${REINPLACE_CMD} '/gtk-doc/d' ${WRKSRC}/Makefile.in
.endif

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

.include <bsd.port.mk>

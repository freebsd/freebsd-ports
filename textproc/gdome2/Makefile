# New ports collection makefile for:	gdome2
# Date created:		7 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdome2
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://gdome2.cs.unibo.it/tarball/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Gnome DOM Engine

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GNOME=	glib20 gnomehack
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_ENV=	GLIB_CONFIG="${LOCALBASE}/bin/pkg-config glib-2.0" CPPFLAGS="-I${LOCALBASE}/include"
PLIST_SUB=	DOCSDIR="share/doc/${DISTNAME}"
INSTALLS_SHLIB=	yes

MAN1=	gdome-config.1

post-patch:
	@${REINPLACE_CMD} -E -e \
		's,^(HTML_DIR *= *).*,\1\$$(prefix)/share/doc,' \
		${WRKSRC}/gtk-doc/Makefile.in
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

# Created by: Rene Hexel <rh@netbsd.org>
# $FreeBSD$
#    $MCom: ports/textproc/scrollkeeper/Makefile,v 1.12 2007/10/17 21:36:13 mezz Exp $

PORTNAME=	scrollkeeper
PORTVERSION=	0.3.14
PORTREVISION=	14
PORTEPOCH=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Open Document Cataloging Project

BUILD_DEPENDS=	intltool-extract:textproc/intltool \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	intltool-extract:textproc/intltool \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

DOCBOOK_VERSION=4.2

CONFLICTS_INSTALL=	rarian-[0-9]*

USES=		bison pathfix gettext gmake tar:bzip2 libtool
USE_GNOME=	libxslt intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --datadir=${PREFIX}/share \
		--with-omfdirs=${PREFIX}/share/omf \
		--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl
PLIST_SUB=	LOCALBASE=${LOCALBASE}
INSTALL_TARGET=	install-strip

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e   \
		's|[(]LN_S[)] -f -n|(LN_S) -f|g'
	@${REINPLACE_CMD} -e 's|/usr/share/locale|${PREFIX}/share/locale|g' \
		${WRKSRC}/libs/scrollkeeper.h.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/extract/dtds/Makefile.in

post-install:
	@${RM} ${STAGEDIR}/var/log/scrollkeeper.log
	@${MKDIR} ${STAGEDIR}/var/db/scrollkeeper

.include <bsd.port.mk>

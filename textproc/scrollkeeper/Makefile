# New ports collection makefile for:	scrollkeeper
# Date created:				6 April 2001
# Whom:					Rene Hexel <rh@netbsd.org>
#
# $FreeBSD$
#    $MCom: ports/textproc/scrollkeeper/Makefile,v 1.7 2007/02/20 20:26:47 marcus Exp $

PORTNAME=	scrollkeeper
PORTVERSION=	0.3.14
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An Open Document Cataloging Project

BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/catalog.xml:${PORTSDIR}/textproc/docbook-xml \
    		${LOCALBASE}/share/xml/docbook/4.1.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-sk
RUN_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
    		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/catalog.xml:${PORTSDIR}/textproc/docbook-xml \
    		${LOCALBASE}/share/xml/docbook/4.1.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-sk

DOCBOOK_VERSION=4.2

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_BISON=	yes
USE_GNOME=	gnomehack gnomehier gnometarget libxslt intlhack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--localstatedir=/var --datadir=${PREFIX}/share/gnome \
		--with-omfdirs=${PREFIX}/share/gnome/omf \
		--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl" \
		LOCALBASE="${LOCALBASE}"
PLIST_SUB=	LOCALBASE=${LOCALBASE}

MAN1=	scrollkeeper-config.1 scrollkeeper-gen-seriesid.1
MAN5=	scrollkeeper.conf.5
MAN7=	scrollkeeper.7
MAN8=	scrollkeeper-preinstall.8 scrollkeeper-rebuilddb.8 \
	scrollkeeper-update.8

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e   \
		's|[(]LN_S[)] -f -n|(LN_S) -f|g'
	@${REINPLACE_CMD} -e 's|/usr/share/locale|${PREFIX}/share/locale|g' \
		${WRKSRC}/libs/scrollkeeper.h.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/extract/dtds/Makefile.in

.include <bsd.port.post.mk>

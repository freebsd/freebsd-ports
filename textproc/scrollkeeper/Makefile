# New ports collection makefile for:	scrollkeeper
# Date created:				6 April 2001
# Whom:					Rene Hexel <rh@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	scrollkeeper
PORTVERSION=	0.3.14
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An Open Document Cataloging Project

BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl

# Don't use USE_X_PREFIX - the port doesn't really require X11 to run.
# The reason why it should be in X11BASE is that GNOME is the primary
# (only?) consumer of this port, and BadThings[tm] happen if it's not
# put in the right place.
PREFIX?=	${X11BASE}

DOCBOOK_VERSION=	4.1.2

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_BISON=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnomehier gnometarget libxslt
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=/var --datadir=${PREFIX}/share/gnome \
		--with-omfdirs=${PREFIX}/share/gnome/omf \
		--with-xml-catalog=${LOCALBASE}/share/xml/catalog
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

.if ${XFREE86_VERSION} == 3
MTREE_FILE=     /etc/mtree/BSD.x11.dist
.else
MTREE_FILE=     /etc/mtree/BSD.x11-4.dist
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e   \
		's|[(]LN_S[)] -f -n|(LN_S) -f|g'
	@${REINPLACE_CMD} -e 's|/usr/share/locale|${PREFIX}/share/locale|g' \
		${WRKSRC}/libs/scrollkeeper.h.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/extract/dtds/Makefile.in

.include <bsd.port.post.mk>

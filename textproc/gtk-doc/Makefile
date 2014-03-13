# Created by: fenner
# $FreeBSD$
#    $MCom: ports/trunk/textproc/gtk-doc/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gtk-doc
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Code documentation system, originally for GTK+

BUILD_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		rarian-sk-config:${PORTSDIR}/textproc/rarian

DOCBOOK_VERSION=	4.1.2

CATALOG_DIR=		${PREFIX}/share/sgml/${PORTNAME}
XMLCATMGR=		${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

USE_PYTHON_RUN=	2
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig shebangfix perl5 tar:xz
USE_GNOME=	gnomeprefix libxslt gnomedocutils
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports
SHEBANG_FILES=	tools/docpercentages.pl

PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML} \
		CATALOG_DIR=${CATALOG_DIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/tests/tools.sh

.include <bsd.port.mk>

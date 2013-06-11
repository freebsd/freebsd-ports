# Created by: fenner
# $FreeBSD$
#    $MCom: ports-stable/textproc/gtk-doc/Makefile,v 1.1 2010/06/24 09:20:01 kwm Exp $

PORTNAME=	gtk-doc
PORTVERSION=	1.15
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Code documentation system, originally for GTK+

BUILD_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		rarian-sk-config:${PORTSDIR}/textproc/rarian

DOCBOOK_VERSION=	4.1.2

CATALOG_DIR=		${PREFIX}/share/sgml/${PORTNAME}
XMLCATMGR=		${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USES=		pathfix shebangfix
USE_GNOME=	gnomehack gnomeprefix libxslt gnomedocutils
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports

SHEBANG_FILES=	tools/docpercentages.pl

PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML} \
		CATALOG_DIR=${CATALOG_DIR}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		-e 's|#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/tests/tools.sh.in \
		${WRKSRC}/tests/fail.sh \
		${WRKSRC}/tests/sanity.sh

post-install:
	-@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${CATALOG_DIR}/gtk-doc.cat

.include <bsd.port.mk>

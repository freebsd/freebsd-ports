# New ports collection makefile for:	gtk-doc
# Date created:				8 March 2001
# Whom:					fenner
#
# $FreeBSD$
#

PORTNAME=	gtk-doc
PORTVERSION=	1.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.6

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Code documentation system, originally for GTK+

BUILD_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

DOCBOOK_VERSION=	4.1.2

CATALOG_DIR=		${PREFIX}/share/sgml/${PORTNAME}
XMLCATMGR=		${LOCALBASE}/bin/xmlcatmgr
CATALOG_PORTS_SGML=	${PREFIX}/share/sgml/catalog.ports

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget libxslt
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports

PLIST_SUB=	XMLCATMGR=${XMLCATMGR} \
		CATALOG_PORTS_SGML=${CATALOG_PORTS_SGML} \
		CATALOG_DIR=${CATALOG_DIR}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		gtk-doc requires Perl 5.6.x or higher
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

post-install:
	@${XMLCATMGR} -sc ${CATALOG_PORTS_SGML} add CATALOG ${CATALOG_DIR}/gtk-doc.cat

.include <bsd.port.post.mk>

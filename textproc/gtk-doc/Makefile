# New ports collection makefile for:	gtk-doc
# Date created:				8 March 2001
# Whom:					fenner
#
# $FreeBSD$
#

PORTNAME=	gtk-doc
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk-doc/

MAINTAINER=	gnome@freebsd.org
COMMENT=	Code documentation system, originally for GTK+

BUILD_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/xml/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl

DOCBOOK_VERSION=	4.1.2

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget libxslt
CONFIGURE_ARGS=	--with-xml-catalog=${LOCALBASE}/share/xml/catalog

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		gtk-doc requires Perl 5.6.x or higher
.endif

.include <bsd.port.post.mk>

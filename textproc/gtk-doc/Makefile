# New ports collection makefile for:	gtk-doc
# Date created:				8 March 2001
# Whom:					fenner
#
# $FreeBSD$
#

PORTNAME=	gtk-doc
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.1/docs/rdp/

MAINTAINER=	gnome@freebsd.org
COMMENT=	Code documentation system, originally for GTK+

BUILD_DEPENDS=	${LOCALBASE}/share/sk/docbook/${DOCBOOK_VERSION}/docbook.cat:${PORTSDIR}/textproc/docbook-sk
RUN_DEPENDS=	jade:${PORTSDIR}/textproc/jade

DOCBOOK_VERSION=	4.1.2

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget libxslt
CONFIGURE_ARGS=	--with-xml-catalog=${LOCALBASE}/share/sk/docbook/${DOCBOOK_VERSION}/docbook.cat

.include <bsd.port.mk>

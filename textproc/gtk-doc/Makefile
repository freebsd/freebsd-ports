# New ports collection makefile for:	gtk-doc
# Date created:				8 March 2001
# Whom:					fenner
#
# $FreeBSD$
#

PORTNAME=	gtk-doc
PORTVERSION=	0.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.1/docs/rdp/

MAINTAINER=	fenner@FreeBSD.Org

BUILD_DEPENDS=	${LOCALBASE}/share/sgml/docbook/dsssl/modular/html/docbook.dsl:${PORTSDIR}/textproc/dsssl-docbook-modular
RUN_DEPENDS=	jade:${PORTSDIR}/textproc/jade

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dsssl-dir=${LOCALBASE}/share/sgml/docbook/dsssl/modular

.include <bsd.port.mk>

# New ports collection makefile for:	gdome2
# Date created:		7 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdome2
PORTVERSION=	0.6.8
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.unibo.it/~casarini/gdome2/tarball/

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

WANT_GLIB=	yes

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" CPPFLAGS="-I${LOCALBASE}/include"
PLIST_SUB=	DOCSDIR="share/doc/${DISTNAME}"

INSTALLS_SHLIB=	yes

post-patch:
	${PERL} -i -pe 's,^(HTML_DIR *= *).*,$$1\$$(prefix)/share/doc,' ${WRKSRC}/gtk-doc/Makefile.in

.include <bsd.port.mk>

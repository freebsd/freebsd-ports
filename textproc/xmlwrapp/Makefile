# ex:ts=8
# Ports collection makefile for:	xmlwrapp
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlwrapp
PORTVERSION=	0.4.4
CATEGORIES=	textproc
MASTER_SITES=	http://pmade.org/software/xmlwrapp/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modern style C++ library for working with XML data

USE_PERL5_BUILD=	yes
USE_GNOME=	libxml2 pkgconfig
WANT_GNOME=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.pl
CONFIGURE_ARGS=	--prefix ${PREFIX}
INSTALLS_SHLIB=	yes
CFLAGS+=	-fPIC

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibxslt}!=""
USE_GNOME+=	libxslt
.else
CONFIGURE_ARGS+=	--disable-xslt
.endif

.include <bsd.port.post.mk>

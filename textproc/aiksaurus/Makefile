# $FreeBSD$
#    $MCom: ports/textproc/aiksaurus/Makefile,v 1.2 2006/09/10 00:51:13 mezz Exp $

PORTNAME=	aiksaurus
PORTVERSION=	1.2.1
PORTREVISION?=	3
CATEGORIES?=	textproc
MASTER_SITES=	SF

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Set of libraries and applications which provide a thesaurus

LICENSE=	GPLv2

USES=		gmake libtool pathfix pkgconfig
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--without-gtk

.include <bsd.port.mk>

# New ports collection makefile for:	aiksaurus
# Date created:				23 July 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/textproc/aiksaurus/Makefile,v 1.2 2006/09/10 00:51:13 mezz Exp $

PORTNAME=	aiksaurus
PORTVERSION=	1.2.1
PORTREVISION?=	2
CATEGORIES?=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aiksaurus

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A set of libraries and applications which provide a thesaurus

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GNOME?=	gnomehack gnometarget
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--without-gtk

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>

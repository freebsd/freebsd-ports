# New ports collection makefile for:	orchard
# Date created:		08 Feb 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	orchard-c
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	orchard
DISTNAME=	Orchard-C-${PORTVERSION}

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		gc:${PORTSDIR}/devel/boehm-gc

USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
USE_PYTHON=	yes
USE_QT_VER=	2
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

MAKE_ENV+=	RM="${RM} -f"
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's,CFLAGS = -I. -g -O2,CFLAGS = -I. \@CFLAGS\@,' \
		${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's,^#!/usr/bin/env python,#!${PYTHON_CMD},' \
		${WRKSRC}/moc.py

.include <bsd.port.mk>

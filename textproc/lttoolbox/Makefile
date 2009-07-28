# New ports collection makefile for:  lttoolbox
# Date created:                14 April 2009
# Whom:                        Mykola Dzham <freebsd@levsha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	lttoolbox
PORTVERSION=	3.1.1
CATEGORIES=	textproc
MASTER_SITES=	SF/apertium

MAINTAINER=	freebsd@levsha.org.ua
COMMENT=	A tool for lexical, morphological analysis and generation of words

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig

MAN1=	lt-comp.1 lt-expand.1 lt-proc.1 lt-tmxcomp.1 lt-tmxproc.1

.include <bsd.port.mk>

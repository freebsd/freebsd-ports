# New ports collection makefile for:	sgmltools
# Date created:				7 Apr 2000
# Whom:					Benno Rice <benno@netizen.com.au>
#
# $FreeBSD$
#

PORTNAME=	sgmltools
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.us.sgmltools.org/pub/SGMLtools/v2.0/source/ \
		ftp://ftp.nllgg.nl/pub/SGMLtools/v2.0/source/
DISTFILES=	${DISTNAME}.base.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates various output formats from DocBook SGML documents

BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python \
		jade:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/texmf:${PORTSDIR}/print/teTeX
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/docbook:${PORTSDIR}/textproc/docbook \
		${LOCALBASE}/share/sgml/docbook/dsssl:${PORTSDIR}/textproc/dsssl-docbook-modular

USE_BZIP2=	yes
USE_PERL5=	yes
MAN1=		sgmltools.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-etcsgml=${PREFIX}/etc/sgml
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	default

.include <bsd.port.mk>

# New ports collection makefile for:	inplace(1)
# Date created:		2 May 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	inplace
PORTVERSION=	1.2.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A tool to edit files in-place through given filter commands

USE_BZIP2=	yes
USE_RUBY=	yes

MAKE_ARGS=	PREFIX="${PREFIX}" MANPREFIX="${MANPREFIX}"
MAKEFILE=	BSDmakefile

RUBY_SHEBANG_FILES=	inplace.rb

MAN1=		inplace.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/inplace

RUBY_REQUIRE=	Ruby > 182

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		only works with Ruby 1.8.0 or later
.endif

.include <bsd.port.post.mk>

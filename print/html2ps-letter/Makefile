# New ports collection makefile for:	html2ps-letter
# Date created:		Sat Nov 22 12:54:50 CET 1997
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	html2ps-${PAPERSIZE}
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print www perl5
MASTER_SITES=	http://www.tdb.uu.se/~jan/
DISTNAME=	html2ps-1.0b3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to PostScript converter

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

BUILD_DEPENDS=	mogrify:${PORTSDIR}/graphics/ImageMagick \
		djpeg:${PORTSDIR}/graphics/jpeg \
		giftopnm:${PORTSDIR}/graphics/netpbm \
		gs:${PORTSDIR}/${GSPORT} \
		tex:${PORTSDIR}/print/teTeX \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		weblint:${PORTSDIR}/www/weblint
RUN_DEPENDS=	mogrify:${PORTSDIR}/graphics/ImageMagick

site_perl=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
USE_PERL5=	YES
NO_BUILD=	YES

PAPERSIZE?=	letter

MAN1=		html2ps.1
MAN5=		html2psrc.5
SCRIPTS_ENV+=	PERL=${PERL} PAPERSIZE=${PAPERSIZE}

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

do-install:
	@cd ${WRKSRC}; ${PERL} install

.include <bsd.port.mk>

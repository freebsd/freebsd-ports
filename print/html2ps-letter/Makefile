# New ports collection makefile for:	html2ps-letter
# Date created:		Sat Nov 22 12:54:50 CET 1997
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	html2ps-${PAPERSIZE}
PORTVERSION=	1.0.b4
PORTEPOCH=	1
CATEGORIES=	print www perl5
MASTER_SITES=	http://user.it.uu.se/~jan/
DISTNAME=	html2ps-1.0b4

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	HTML to PostScript converter

USE_GHOSTSCRIPT_BUILD=	yes

RUN_DEPENDS=	mogrify:${PORTSDIR}/graphics/ImageMagick \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		weblint:${PORTSDIR}/www/weblint

USE_PERL5=	YES
NO_BUILD=	YES

PAPERSIZE?=	letter

MAN1=		html2ps.1
MAN5=		html2psrc.5
SCRIPTS_ENV+=	PERL=${PERL} PAPERSIZE=${PAPERSIZE}

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

do-install:
	@cd ${WRKSRC}; ${PERL} install

.include <bsd.port.mk>

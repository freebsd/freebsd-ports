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

BUILD_DEPENDS=	mogrify:${PORTSDIR}/graphics/ImageMagick \
		djpeg:${PORTSDIR}/graphics/jpeg \
		giftopnm:${PORTSDIR}/graphics/netpbm \
		gs:${PORTSDIR}/print/ghostscript55 \
		tex:${PORTSDIR}/print/teTeX \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		weblint:${PORTSDIR}/www/weblint

site_perl=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
USE_PERL5=	YES
NO_BUILD=	YES

PAPERSIZE?=	letter

MAN1=		html2ps.1
MAN5=		html2psrc.5
SCRIPTS_ENV+=	PERL=${PERL} PAPERSIZE=${PAPERSIZE}

do-install:
	@cd ${WRKSRC}; ${PERL} install

.include <bsd.port.mk>

# New ports collection makefile for:	html2ps
# Version required:	1.0b1
# Date created:		Sat Nov 22 12:54:50 CET 1997
# Whom:			andreas
#
# $Id: Makefile,v 1.2 1998/08/31 13:16:21 asami Exp $
#

DISTNAME=	html2ps-1.0b1
PKGNAME=	html2ps-1.0
CATEGORIES=	lang www perl5
MASTER_SITES=	http://www.tdb.uu.se/~jan/

MAINTAINER=	andreas@FreeBSD.ORG

BUILD_DEPENDS=	mogrify:${PORTSDIR}/graphics/ImageMagick \
		djpeg:${PORTSDIR}/graphics/jpeg \
		giftopnm:${PORTSDIR}/graphics/netpbm \
		gs:${PORTSDIR}/print/ghostscript5 \
		tex:${PORTSDIR}/print/teTeX \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		weblint:${PORTSDIR}/www/weblint

site_perl=	${PREFIX}/lib/perl5/site_perl
USE_PERL5=	YES
NO_BUILD=	YES
IS_INTERACTIVE=	YES

MAN1=		html2ps.1
MAN5=		html2psrc.5

do-install:
	@cd ${WRKSRC}; ${PERL5} install

.include <bsd.port.mk>

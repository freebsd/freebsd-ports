# ex:ts=8
# Ports collection makefile for:	p5-PDF-API2
# Date created:			Feb 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	PDF-API2
PORTVERSION=	0.2.3.7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}_dev

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PERL_SITELIBDIR}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${PERL_SITELIBDIR}/Text/PDF/Pages.pm:${PORTSDIR}/print/p5-Text-PDF \
		${PERL_SITELIBDIR}/Font/TTF/AATKern.pm:${PORTSDIR}/x11-fonts/p5-Font-TTF
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
PERL_SITELIBDIR=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	p5-PDF-API2
# Date created:			Feb 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	PDF-API2
PORTVERSION=	0.69
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	'The Next Generation' of Text::PDF::API

BUILD_DEPENDS=	${PERL_SITELIBDIR}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+
PERL_SITELIBDIR=	${SITE_PERL}

.include <bsd.port.mk>

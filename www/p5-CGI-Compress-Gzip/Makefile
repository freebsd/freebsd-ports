# New ports collection makefile for:	www/p5-CGI-Compress-Gzip
# Date created:				11 September 2008
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Compress-Gzip
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	CGI::Compress::Gzip - CGI with automatically compressed output

BUILD_DEPENDS=	p5-IO-Zlib>=1.01:${PORTSDIR}/archivers/p5-IO-Zlib \
		p5-Compress-Zlib>=2:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	CGI::Compress::Gzip.3 \
	CGI::Compress::Gzip::FileHandle.3

.include <bsd.port.mk>

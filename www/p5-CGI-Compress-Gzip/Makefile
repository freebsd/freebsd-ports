# New ports collection makefile for:	www/p5-CGI-Compress-Gzip
# Date created:				11 September 2008
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Compress-Gzip
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	CGI::Compress::Gzip - CGI with automatically compressed output

BUILD_DEPENDS=	p5-IO-Zlib>=1.01:${PORTSDIR}/archivers/p5-IO-Zlib
RUN_DEPENDS=	p5-IO-Zlib>=1.01:${PORTSDIR}/archivers/p5-IO-Zlib

PERL_MODBUILD=	yes

MAN3=	CGI::Compress::Gzip.3 \
	CGI::Compress::Gzip::FileHandle.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>

# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CGI-Compress-Gzip
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	CGI::Compress::Gzip - CGI with automatically compressed output

BUILD_DEPENDS=	p5-IO-Zlib>=1.01:${PORTSDIR}/archivers/p5-IO-Zlib
RUN_DEPENDS=	p5-IO-Zlib>=1.01:${PORTSDIR}/archivers/p5-IO-Zlib

USES=		perl5
USE_PERL5=	modbuild

MAN3=	CGI::Compress::Gzip.3 \
	CGI::Compress::Gzip::FileHandle.3

.include <bsd.port.mk>

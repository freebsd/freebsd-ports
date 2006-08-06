# New ports collection makefile for:	p5-File-Format-RIFF
# Date created:		23 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Format-RIFF
DISTVERSION=	1.0.1
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Read, manipulate, and write RIFF files

PERL_CONFIGURE=	YES

MAN3=		File::Format::RIFF.3 \
		File::Format::RIFF::Chunk.3 \
		File::Format::RIFF::Container.3 \
		File::Format::RIFF::List.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>

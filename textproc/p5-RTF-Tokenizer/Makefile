# New ports collection makefile for:	textproc/p5-RTF-Tokenizer
# Date created:				Oct 15th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	RTF-Tokenizer
PORTVERSION=	1.10
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for reading RTF files

PERL_CONFIGURE=	yes

MAN3=	RTF::Tokenizer.3

post-patch:
	@${FIND} ${WRKSRC} -name ._Tokenizer.pm -delete

.include <bsd.port.mk>

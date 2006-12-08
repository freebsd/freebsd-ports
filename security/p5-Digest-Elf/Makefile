# Ports collection Makefile for:	p5-Digest-Elf
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Elf
PORTVERSION=	1.4
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for ElfHash hash algorithm

PERL_CONFIGURE=	yes

MAN3=	Digest::Elf.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Elf.pm
	${PERL} -pi -e '$$_="" if m{5.006|warnings}' ${WRKSRC}/Elf.pm
.endif

.include <bsd.port.post.mk>

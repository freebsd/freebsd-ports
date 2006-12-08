# Ports collection Makefile for:	p5-Digest-Pearson
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Pearson
PORTVERSION=	1.00
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for Peter K. Pearson's hash algorithm

PERL_CONFIGURE=	yes

MAN3=	Digest::Pearson.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Pearson.pm
	${PERL} -pi -e '$$_="" if m{5.006|warnings}' ${WRKSRC}/Pearson.pm
.endif

.include <bsd.port.post.mk>

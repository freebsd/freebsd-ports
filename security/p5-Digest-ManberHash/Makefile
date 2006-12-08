# Ports collection Makefile for:	p5-Digest-ManberHash
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-ManberHash
PORTVERSION=	0.7
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for ManberHash hash algorithm

PERL_CONFIGURE=	yes

MAN3=	Digest::ManberHash.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-ManberHash.xs

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/ManberHash.pm
.endif

.include <bsd.port.post.mk>

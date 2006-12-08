# Ports collection Makefile for:	p5-Digest-FNV
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-FNV
PORTVERSION=	1.00
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for Fowler/Noll/Vo hash algorithm

PERL_CONFIGURE=	yes

MAN3=	Digest::FNV.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-FNV.xs

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/FNV.pm
	${PERL} -pi -e '$$_="" if m{5.006|warnings}' ${WRKSRC}/FNV.pm
	${PERL} -pi -e 's/ our / my /' ${WRKSRC}/FNV.pm
.endif

.include <bsd.port.post.mk>

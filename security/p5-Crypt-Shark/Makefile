# New ports collection Makefile for:	p5-Crypt-Shark
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Shark
PORTVERSION=	1.0.1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for Shark block cipher

PERL_CONFIGURE=	yes

MAN3=		Crypt::Shark.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
RUN_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Shark.xs

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Shark.pm
	${PERL} -pi -e 's/void/int argc, char**argv, char**env/ if m{int main}' ${WRKSRC}/_shark.c
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/Shark.pm ${WRKSRC}/t/*.t
.endif

.include <bsd.port.post.mk>

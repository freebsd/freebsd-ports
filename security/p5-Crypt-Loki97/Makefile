# New ports collection Makefile for:	p5-Crypt-Loki97
# Date created:				20 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Loki97
PORTVERSION=	1.0.1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for Loki97 block cipher

PERL_CONFIGURE=	yes

MAN3=		Crypt::Loki97.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
RUN_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Loki97.xs

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Loki97.pm
	${PERL} -pi -e 's/void/int argc, char**argv, char**env/ if m{int main}' ${WRKSRC}/_loki97.c
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/Loki97.pm ${WRKSRC}/t/*.t
.endif

.include <bsd.port.post.mk>

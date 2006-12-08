# New ports collection Makefile for:	p5-Crypt-Rabbit
# Date created:				18 Dec 2006
# Whom:	      				Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Crypt-Rabbit
PORTVERSION=	1.0.0
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for Rabbit stream cipher

PERL_CONFIGURE=	yes

MAN3=		Crypt::Rabbit.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
RUN_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-Rabbit.xs

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Rabbit.pm
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/Rabbit.pm ${WRKSRC}/t/*.t
.endif

.include <bsd.port.post.mk>

# Ports collection makefile for:	p5-Digest-SHA
# Date created:			Aug 4, 2005
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Digest-SHA
PORTVERSION=	5.34
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	Perl extension for SHA-1/224/256/384/512

PERL_CONFIGURE=	yes

MAN1=	shasum.1
MAN3=	Digest::SHA.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
RUN_DEPENDS+=	${SITE_PERL}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/SHA.pm
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/SHA.pm
.endif

.include <bsd.port.post.mk>

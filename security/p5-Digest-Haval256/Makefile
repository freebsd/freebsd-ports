# Ports collection Makefile for:	p5-Digest-Haval256
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-Haval256
PORTVERSION=	1.0.5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for Haval256 hash algorithm

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE=	yes

MAN3=	Digest::Haval256.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-Haval256.xs

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/Haval256.pm
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/Haval256.pm ${WRKSRC}/t/*.t
	${PERL} -pi -e 's/\)/, char **env\)/ if m{int main}' ${WRKSRC}/_haval.c
.endif

.include <bsd.port.post.mk>

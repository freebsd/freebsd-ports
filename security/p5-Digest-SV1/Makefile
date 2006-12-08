# Ports collection Makefile for:	p5-Digest-SV1
# Date created:				17 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	Digest-SV1
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Perl extension for SV1 hash algorithm

BUILD_DEPENDS=	${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/Haval256.pm:${PORTSDIR}/security/p5-Digest-Haval256

PERL_MODBUILD=	yes

MAN3=	Digest::SV1.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	#${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/SV1.pm
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/lib/Digest/SV1.pm
.endif

.include <bsd.port.post.mk>

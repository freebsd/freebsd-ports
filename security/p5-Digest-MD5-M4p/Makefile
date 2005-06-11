# New ports collection makefile for:	p5-Digest-MD5-M4p
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Digest-MD5-M4p
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl interface to a variant of the MD5 algorithm

BUILD_DEPENDS=	${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Digest::MD5::M4p.3

post-extract:
	@${PERL} -pi -e 's/\r//g' ${WRKSRC}/M4p.xs

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
post-configure:
	@${PERL} -pi -e '$$_="" if /use warnings/' ${WRKSRC}/M4p.pm
	# make PREFIX-clean under perl 5.005_03
	@${PERL} -pi -e 's,/usr/local/,\$${PREFIX}/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:    p5-URI
# Date created:				1999/04/07
# Whom:					ache
#
# $FreeBSD$
#

PORTNAME=	URI
PORTVERSION=	1.35
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl5 interface to Uniform Resource Identifier (URI) references

PERL_CONFIGURE=	yes

MAN3=		URI.3 \
		URI::Escape.3 \
		URI::Heuristic.3 \
		URI::QueryParam.3 \
		URI::Split.3 \
		URI::URL.3 \
		URI::WithBase.3 \
		URI::data.3 \
		URI::file.3 \
		URI::ldap.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);/' \
		${WRKSRC}/URI/urn.pm

.include <bsd.port.post.mk>

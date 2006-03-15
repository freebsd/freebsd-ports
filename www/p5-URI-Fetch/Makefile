# New ports collection makefile for:	www/p5-URI-Fetch
# Date created:				30 July 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-Fetch
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Smart URI fetching/caching

BUILD_DEPENDS=	${SITE_PERL}/Class/ErrorHandler.pm:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	ZLIB "GZIP Support" on \
		CACHE "Caching Support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ZLIB)
BUILD_DEPENDS+=	p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS+=	p5-Compress-Zlib>=0:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

.if defined(WITH_CACHE)
BUILD_DEPENDS+=	p5-Cache>=0:${PORTSDIR}/devel/p5-Cache
RUN_DEPENDS+=	p5-Cache>=0:${PORTSDIR}/devel/p5-Cache
.endif

PERL_MODBUILD=	yes

MAN3=	URI::Fetch.3 \
	URI::Fetch::Response.3

post-patch:
	${PERL} -pi -e '$$_ = "" if m|auto_install|' ${WRKSRC}/Makefile.PL

.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or later. Please install lang/perl5 or lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>

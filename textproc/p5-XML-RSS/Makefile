# New ports collection makefile for:	XML::RSS
# Date created:				4th September 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS
PORTVERSION=	1.05
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl extension to manage RDF Site Summary (RSS) files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Test/Manifest.pm:${PORTSDIR}/devel/p5-Test-Manifest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::RSS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>

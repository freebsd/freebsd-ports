# ex:ts=8
# Ports collection makefile for:	XML::Catalog
# Date created:			Jan 24, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	XML-Catalog
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resolve public identifiers and remap system identifiers

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Catalog.3

post-patch:
	${PERL} -pi -e 's/\r//' ${WRKSRC}/Catalog.pm

.include <bsd.port.mk>

# New ports collection makefile for:    p5-Locale-Geocode
# Date created:				2008/08/31
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Locale-Geocode
PORTVERSION=	1.11
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Find codes and information on geographical location

BUILD_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-XML-SAX-Expat>=0:${PORTSDIR}/textproc/p5-XML-SAX-Expat \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Locale::Geocode.3 \
		Locale::Geocode::Division.3 \
		Locale::Geocode::Territory.3

.include <bsd.port.mk>

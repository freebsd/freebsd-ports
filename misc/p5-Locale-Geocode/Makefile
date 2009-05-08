# New ports collection makefile for:    p5-Locale-Geocode
# Date created:				2008/08/31
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Locale-Geocode
PORTVERSION=	1.20
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Find codes and information on geographical location

MAKE_JOBS_SAFE=	yes

RUN_DEPENDS=	p5-XML-SAX-Expat>=0.39:${PORTSDIR}/textproc/p5-XML-SAX-Expat \
		p5-XML-Simple>=2.16:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Locale::Geocode.3 \
		Locale::Geocode::Division.3 \
		Locale::Geocode::Territory.3

.include <bsd.port.mk>

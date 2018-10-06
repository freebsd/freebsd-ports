# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	libxml
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/XML
PKGNAMEPREFIX=	p5-
DISTNAME=	libxml-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of Perl5 modules for working with XML

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>

# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTNAME=	WebService-MusicBrainz
PORTVERSION=	0.94
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	0

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Perl interface to MusicBrainz

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>

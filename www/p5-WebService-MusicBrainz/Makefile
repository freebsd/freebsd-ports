PORTNAME=	WebService-MusicBrainz
DISTVERSION=	1.0.7
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl interface to MusicBrainz
WWW=		https://metacpan.org/release/WebService-MusicBrainz

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-libwww>=0:www/p5-libwww \
		p5-Mojolicious>=7.13:www/p5-Mojolicious \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

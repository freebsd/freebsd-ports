# New ports collection makefile for:	p5-WebService-Rakuten
# Date created:				2008/05/28
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	WebService-Rakuten
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Rakuten WebService API

BUILD_DEPENDS=	p5-Data-Page>=0:${PORTSDIR}/databases/p5-Data-Page \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		WebService::Rakuten::GenreResult.3 \
		WebService::Rakuten::Item.3 \
		WebService::Rakuten::Parser.3 \
		WebService::Rakuten::ItemResult.3 \
		WebService::Rakuten.3 \
		WebService::Rakuten::Genre.3

PLIST_FILES=	%%SITE_PERL%%/WebService/Rakuten.pm \
		%%SITE_PERL%%/WebService/Rakuten/GenreResult.pm \
		%%SITE_PERL%%/WebService/Rakuten/Item.pm \
		%%SITE_PERL%%/WebService/Rakuten/ItemResult.pm \
		%%SITE_PERL%%/WebService/Rakuten/Parser.pm \
		%%SITE_PERL%%/WebService/Rakuten/Genre.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WebService/Rakuten/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/WebService/Rakuten \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WebService \
		%%SITE_PERL%%/WebService/Rakuten \
		%%SITE_PERL%%/WebService

.include <bsd.port.mk>

# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	AMF-Perl
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SIMONF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flash Remoting in Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Exception-Class>=0:devel/p5-Exception-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure patch

post-patch:
	@${REINPLACE_CMD} -e 's|=\(=head\)|\1|' ${WRKSRC}/lib/AMF/Perl.pm

.include <bsd.port.mk>

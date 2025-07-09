PORTNAME=	MogileFS-Client
PORTVERSION=	1.17
PORTREVISION=	2
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client library for the MogileFS distributed file system
WWW=		https://metacpan.org/release/MogileFS-Client

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Stringy>=2.102:devel/p5-IO-Stringy \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

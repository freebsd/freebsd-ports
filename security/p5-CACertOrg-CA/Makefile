PORTNAME=	CACertOrg-CA
PORTVERSION=	20210114.003
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRIANDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CACert.org CA root certificate in PEM format
WWW=		https://metacpan.org/release/CACertOrg-CA

LICENSE=	CACERT
LICENSE_NAME=	CAcert Root Distribution License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>

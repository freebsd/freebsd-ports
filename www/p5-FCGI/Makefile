PORTNAME=	FCGI
PORTVERSION=	0.82
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules for perl5, for enabling FastCGI support in CGI scripts

LICENSE=	OpenMarket
LICENSE_NAME=	Open Market License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	p5-FCGI-Client>=0:www/p5-FCGI-Client

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/FCGI/FCGI.so

.include <bsd.port.mk>

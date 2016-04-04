# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Yahoo-BBAuth
PORTVERSION=	0.50
PORTREVISION=	1
CATEGORIES=	security www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to the Yahoo! Browser-Based Authentication

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-JSON>=0:converters/p5-JSON \
		p5-libwww>=5.6:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5 shebangfix

SHEBANG_FILES=	eg/*.cgi

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${STAGEDIR}${WWWDIR}/cgi-bin/

.include <bsd.port.mk>

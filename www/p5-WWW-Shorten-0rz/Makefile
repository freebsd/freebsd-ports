# Created by: Tsung-Han Yeh <snowfly@yuntech.edu.tw>
# $FreeBSD$

PORTNAME=	WWW-Shorten-0rz
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Shorten URL using 0rz.net

BUILD_DEPENDS=	p5-WWW-Shorten>=0:www/p5-WWW-Shorten \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

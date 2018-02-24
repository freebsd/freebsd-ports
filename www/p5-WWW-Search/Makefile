# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Search
PORTVERSION=	2.517
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for WWW searches

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-CGI>=0:www/p5-CGI \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-HTML-Parser>=2.23:www/p5-HTML-Parser \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-URI>=0:net/p5-URI \
		p5-User>=0:sysutils/p5-User \
		p5-libwww>=2:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-Capture>=0:devel/p5-IO-Capture \
		p5-Test-File>=0:devel/p5-Test-File

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

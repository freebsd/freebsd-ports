# $FreeBSD$

PORTNAME=	Tk-Clock
PORTVERSION=	0.40
CATEGORIES=	x11-clocks perl5 tk
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bscott@bunyatech.com.au
COMMENT=	Clock widget with analog and digital display

LICENSE=	ARTPERL10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings \
		p5-Tk>=804:x11-toolkits/p5-Tk

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes
PLIST_FILES=	${SITE_PERL_REL}/Tk/Clock.pm \
	       	${SITE_MAN3_REL}/Tk::Clock.3.gz

.include <bsd.port.mk>

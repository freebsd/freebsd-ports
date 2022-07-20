PORTNAME=	Dancer-Plugin-Auth-Extensible
PORTVERSION=	1.00
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible authentication framework for Dancer apps

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-SaltedHash>=0:security/p5-Crypt-SaltedHash \
		p5-Dancer>=1.3118:www/p5-Dancer

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DPAEPD DPAEPU
DPAEPD_DESC=	Extra dependencies for Provider::Database
DPAEPU_DESC=	Extra dependencies for Provider::Unix

DPAEPD_BUILD_DEPENDS=	p5-Dancer-Plugin-Database>=0:databases/p5-Dancer-Plugin-Database
DPAEPU_BUILD_DEPENDS=	p5-Authen-Simple-PAM>=0:security/p5-Authen-Simple-PAM \
			p5-Unix-Passwd-File>=0:security/p5-Unix-Passwd-File

.include <bsd.port.mk>

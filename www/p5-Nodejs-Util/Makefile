PORTNAME=	Nodejs-Util
PORTVERSION=	0.012
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities related to Node.js
WWW=		https://metacpan.org/dist/Nodejs-Util

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-IPC-System-Options>=0.330:devel/p5-IPC-System-Options
TEST_DEPENDS=	p5-File-Slurper>=0:devel/p5-File-Slurper \
		p5-File-chdir>=0:devel/p5-File-chdir

USES=		nodejs:run perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

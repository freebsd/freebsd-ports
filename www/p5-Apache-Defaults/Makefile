PORTNAME=	Apache-Defaults
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get default settings for Apache httpd daemon

LICENSE=	GPLv3+

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime-Format-Strptime>=1.54:devel/p5-DateTime-Format-Strptime \
		p5-Shell-GetEnv>=0.10:devel/p5-Shell-GetEnv

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

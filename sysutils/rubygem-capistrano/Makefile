PORTNAME=	capistrano
PORTVERSION=	3.17.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility for executing commands in parallel on multiple machines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-airbrussh>=1.0.0:security/rubygem-airbrussh \
		rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-rake>=10.0.0:devel/rubygem-rake \
		rubygem-sshkit>=1.9.0:security/rubygem-sshkit

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cap bin/capify

.include <bsd.port.mk>

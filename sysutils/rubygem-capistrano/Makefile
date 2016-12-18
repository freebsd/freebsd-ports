# Created by: Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
# $FreeBSD$

PORTNAME=	capistrano
PORTVERSION=	3.7.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility for executing commands in parallel on multiple machines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-airbrussh>=1.0.0:security/rubygem-airbrussh \
		rubygem-capistrano-harrow>=0:sysutils/rubygem-capistrano-harrow \
		rubygem-i18n>=0:devel/rubygem-i18n \
		rubygem-rake>=10.0.0:devel/rubygem-rake \
		rubygem-sshkit>=1.9.0:security/rubygem-sshkit

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/cap bin/capify

.include <bsd.port.mk>

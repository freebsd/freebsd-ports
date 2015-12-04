# Created by: Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
# $FreeBSD$

PORTNAME=	capistrano
PORTVERSION=	3.4.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility for executing commands in parallel on multiple machines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-i18n>=0:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-rake>=10:${PORTSDIR}/devel/rubygem-rake \
		rubygem-sshkit>=1.3:${PORTSDIR}/security/rubygem-sshkit

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/cap bin/capify

.include <bsd.port.mk>

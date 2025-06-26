PORTNAME=	rubyipmi
PORTVERSION=	0.12.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Command line wrapper for ipmitool and freeipmi
WWW=		https://github.com/logicminds/rubyipmi

LICENSE=	LGPL21

RUN_DEPENDS=	${LOCALBASE}/sbin/bmc-device:sysutils/freeipmi \
		rubygem-logger>=0:devel/rubygem-logger \
		rubygem-observer>=0.1.0<0.2:devel/rubygem-observer

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>

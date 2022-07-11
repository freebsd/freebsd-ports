PORTNAME=	rack
PORTVERSION=	2.2.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	223

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rack, a Ruby Webserver Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rack_project

PORTSCOUT=	limit:^2\.2\.3\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>

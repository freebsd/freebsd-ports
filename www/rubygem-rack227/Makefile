PORTNAME=	rack
PORTVERSION=	2.2.7
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	227

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rack, a Ruby Webserver Interface
WWW=		https://github.com/rack/rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rack_project

PORTSCOUT=	limit:^2\.2\.7\.

# Avoid CONFLICTS_INSTALL with www/rubygem-rack22
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>

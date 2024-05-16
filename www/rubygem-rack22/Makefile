PORTNAME=	rack
PORTVERSION=	2.2.9
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rack, a modular Ruby web server interface
WWW=		https://github.com/rack/rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rack_project

PORTSCOUT=	limit:^2\.2\.

# Avoid CONFLICTS_INSTALL with www/rubygem-rackup
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>

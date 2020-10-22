# $FreeBSD$

PORTNAME=	rack
PORTVERSION=	2.1.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	21

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rack, a Ruby Webserver Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.1\.

#rackup_OLD_CMD=	../../bin/rackup
#rackup_CMD=	${PREFIX}/bin/rackup

# Avoid CONFLICTS_INSTALL with www/rubygem-rack
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/rackup

.include <bsd.port.mk>

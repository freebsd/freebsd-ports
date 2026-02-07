PORTNAME=	dotenv
PORTVERSION=	3.2.0
CATEGORIES=	misc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Loads environment variables from .env
WWW=		https://github.com/bkeepers/dotenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/dotenv

CONFLICTS_INSTALL=	py*-python-dotenv # bin/dotenv

.include <bsd.port.mk>

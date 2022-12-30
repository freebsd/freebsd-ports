PORTNAME=	cvss-suite
PORTVERSION=	3.0.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby binding to process CVSS entries
WWW=		https://github.com/0llirocks/cvss-suite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>

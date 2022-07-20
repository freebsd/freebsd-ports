PORTNAME=	kramdown
PORTVERSION=	1.17.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet-another-markdown-parser but fast, pure Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	kramdown_project

PORTSCOUT=	limit:^1\.

SHEBANG_FILES=	benchmark/*.sh

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/kramdown

.include <bsd.port.mk>

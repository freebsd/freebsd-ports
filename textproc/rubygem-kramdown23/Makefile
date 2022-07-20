PORTNAME=	kramdown
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	23

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet-another-markdown-parser but fast, pure Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-rexml>=0:textproc/rubygem-rexml

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	kramdown_project

PORTSCOUT=	limit:^2\.3\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/kramdown

.include <bsd.port.mk>

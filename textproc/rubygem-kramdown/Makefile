PORTNAME=	kramdown
PORTVERSION=	2.5.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Yet-another-markdown-parser but fast, pure Ruby
WWW=		https://kramdown.gettalong.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-rexml>=3.4.4:textproc/rubygem-rexml

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/kramdown

CPE_VENDOR=	kramdown_project

.include <bsd.port.mk>

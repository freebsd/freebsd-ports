# Created by: Steve Wills <swills@rubick>
# $FreeBSD$

PORTNAME=	kramdown
PORTVERSION=	2.2.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Yet-another-markdown-parser but fast, pure Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-rexml>=0:textproc/rubygem-rexml

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/kramdown

.include <bsd.port.mk>

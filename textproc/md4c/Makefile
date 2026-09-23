PORTNAME=	md4c
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	textproc

MAINTAINER=	fsbruva@yahoo.com
COMMENT=	Markdown Parser written in C
WWW=		https://github.com/mity/md4c/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake cpe
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	mity
USE_LDCONFIG=	yes

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>

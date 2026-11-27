PORTNAME=	puma
PORTVERSION=	8.0.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server
WWW=		https://puma.io/ \
		https://github.com/puma/puma

LICENSE=	BSD-3-Clause
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nio4r>=2.0<3:devel/rubygem-nio4r

USES=		cpe gem ssl

PLIST_FILES=	bin/puma bin/pumactl

.include <bsd.port.mk>

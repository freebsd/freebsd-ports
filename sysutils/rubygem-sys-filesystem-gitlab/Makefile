PORTNAME=	sys-filesystem
PORTVERSION=	1.5.5
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby interface for getting filesystem information
WWW=		https://github.com/djberg96/sys-filesystem

LICENSE=	Apache-2.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi>=1.1<2:devel/rubygem-ffi

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.5\.

.include <bsd.port.mk>

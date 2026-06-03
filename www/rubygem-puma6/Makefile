PORTNAME=	puma
PORTVERSION=	6.6.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server
WWW=		https://puma.io/ \
		https://github.com/puma/puma

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nio4r>=2.0<3:devel/rubygem-nio4r

USES=		cpe gem ssl

PORTSCOUT=	limit:^6\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/puma ${STAGEDIR}${PREFIX}/bin/pumactl

.include <bsd.port.mk>

PORTNAME=	chef-bin
PORTVERSION=	17.10.68
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	17

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Chef-branded binstubs for chef-client
WWW=		https://github.com/chef/chef/tree/main/chef-bin

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef17>=${PORTVERSION}<${PORTVERSION}_99:sysutils/rubygem-chef17

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^17\.

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/chef-*

.include <bsd.port.mk>

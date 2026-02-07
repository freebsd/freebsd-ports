PORTNAME=	haml
PORTVERSION=	5.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Markup language to describe HTML
WWW=		https://haml.info/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-temple>=0.8.0:devel/rubygem-temple \
		rubygem-tilt>=0:devel/rubygem-tilt

USES=		cpe gem

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/haml

.include <bsd.port.mk>

# Created by: Steve Wills <swills@freebsd.org>

PORTNAME=	puma
PORTVERSION=	5.5.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nio4r>=2.0<3:devel/rubygem-nio4r

USES=		cpe gem ssl
USE_RUBY=	yes

PLIST_FILES=	bin/puma bin/pumactl

.include <bsd.port.mk>

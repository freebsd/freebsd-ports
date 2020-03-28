# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	gitlab-puma
DISTVERSION=	4.3.3.gitlab.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Fast, multithreaded and highly concurrent ruby web server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nio4r>=2.0<3:devel/rubygem-nio4r

USES=		gem shebangfix ssl
USE_RUBY=	yes

PLIST_FILES=	bin/gpuma bin/gpumactl
#PLIST_FILES=	bin/puma bin/pumactl

SHEBANG_FILES=	tools/jungle/init.d/run-puma

post-install:
		${MV} ${STAGEDIR}${PREFIX}/bin/puma ${STAGEDIR}${PREFIX}/bin/gpuma
		${MV} ${STAGEDIR}${PREFIX}/bin/pumactl ${STAGEDIR}${PREFIX}/bin/gpumactl

.include <bsd.port.mk>

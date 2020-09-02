# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	gitlab-puma
PORTVERSION=	4.3.5.gitlab.3
PORTREVISION=	0
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

post-patch:
		${MV} ${WRKSRC}/bin/puma ${WRKSRC}/bin/gpuma
		${MV} ${WRKSRC}/bin/pumactl ${WRKSRC}/bin/gpumactl

.include <bsd.port.mk>

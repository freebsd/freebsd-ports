# $FreeBSD$

PORTNAME=		mmve
PORTVERSION=		0.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=		sysutils

MAINTAINER=	tj+freebsd_ports@a13.fr
COMMENT=	Mass MV Editor: move files with your text editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-baf>=0.11.0:devel/rubygem-baf

USES=		shebangfix

SHEBANG_FILES=	bin/mmve
USE_RUBY=	yes
NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	tjouan

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mmve ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}

.include <bsd.port.mk>

PORTNAME=	pkg_tree
DISTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://www.mavetju.org/download/

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Get a 'graphical' tree-overview of installed packages
WWW=		https://www.mavetju.org/unix/general.php

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 shebangfix
SHEBANG_FILES=	pkg_tree
NO_ARCH=	yes
PLIST_FILES=	bin/pkg_tree \
		share/man/man7/pkg_tree.7.gz

.include <bsd.port.mk>

# Created by: roam@orbitel.bg
# $FreeBSD$

PORTNAME=	pslist
PORTVERSION=	1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/files/sys/pslist/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Utility to view or send signals to processes with all their children

LICENSE=	BSD2CLAUSE
#LICENSE_FILE=	${WRKSRC}/README # License on 4th paragraph

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	pslist
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" INSTALL_SCRIPT="${INSTALL_SCRIPT}"
NO_ARCH=	yes

.include <bsd.port.mk>

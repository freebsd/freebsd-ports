PORTNAME=	portdowngrade
PORTVERSION=	1.7
CATEGORIES=	ports-mgmt
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Sets a port back to a previous version

LICENSE=	PD

NO_BUILD=	yes
PLIST_FILES=	sbin/portdowngrade

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>

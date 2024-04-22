PORTNAME=	personality
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System configuration management utility to alter system personality

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	share/man/man8/${PORTNAME}.8.gz sbin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>

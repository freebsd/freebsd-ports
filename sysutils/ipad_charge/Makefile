# $FreeBSD$

PORTNAME=	ipad_charge
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic iPad USB charging utility

LICENSE=	BSD2CLAUSE

PLIST_FILES=	etc/devd/ipad_charge.conf
USE_RC_SUBR=	ipad_charge
SUB_FILES=	ipad_charge.conf pkg-message
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKDIR}/ipad_charge.conf ${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>

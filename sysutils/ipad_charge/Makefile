# $FreeBSD$

PORTNAME=	ipad_charge
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
DISTFILES=	# empty

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Generic iPad USB charging utility

LICENSE=	BSD

PLIST_FILES=	etc/devd/ipad_charge.conf
USE_RC_SUBR=	ipad_charge
SUB_FILES=	ipad_charge.conf pkg-message
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${INSTALL_DATA} ${WRKDIR}/ipad_charge.conf ${PREFIX}/etc/devd

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>

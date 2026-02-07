PORTNAME=	remarkable-devd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	Devd hotplug rules for Remarkable Tablet

LICENSE=	BSD2CLAUSE

USE_RC_SUBR=	remarkable

NO_BUILD=	yes

SUB_FILES=	pkg-message \
		remarkable.conf

PLIST_FILES=	etc/devd/remarkable.conf

do-install:
	${INSTALL_DATA} ${WRKDIR}/remarkable.conf ${STAGEDIR}${PREFIX}/etc/devd/remarkable.conf
	${INSTALL_SCRIPT} ${WRKDIR}/remarkable ${STAGEDIR}${PREFIX}/etc/rc.d/remarkable

.include <bsd.port.mk>

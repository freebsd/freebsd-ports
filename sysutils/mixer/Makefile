PORTNAME=	mixer
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	mwm@mired.org
COMMENT=	Startup/shutdown script to preserve mixer settings across reboots

NO_BUILD=	yes
PLIST_FILES=	etc/rc.d/mixer.sh

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/mixer.sh ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>

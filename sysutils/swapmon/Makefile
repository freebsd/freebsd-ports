# Created by: Alexander Kuehn <freebsd@nagilum.org>
# $FreeBSD$

PORTNAME=	swapmon
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	freebsd@nagilum.org
COMMENT=	Add/remove swapspace as needed

LICENSE=	BSD

NO_BUILD=	yes
MAN1=		${PORTNAME}.1

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	sbin/${PORTNAME}

NO_STAGE=	yes
do-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/${PORTNAME}.sh.in \
		> ${WRKDIR}/${PORTNAME}.sh
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${PREFIX}/man/man1

post-install:
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"To have swapmon run automatically after each boot"
	@${ECHO_MSG}	"execute the following command as root:"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"  echo '${PORTNAME}_enable=\"YES\"' >>/etc/rc.conf"
	@${ECHO_MSG}	""

.include <bsd.port.mk>

# Created by: Alexander Kuehn <freebsd@nagilum.org>
# $FreeBSD$

PORTNAME=	swapmon
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Add/remove swapspace as needed

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes

USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	sbin/swapmon man/man1/swapmon.1.gz

post-extract:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/${PORTNAME}.sh.in \
		> ${WRKDIR}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

post-install:
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"To have swapmon run automatically after each boot"
	@${ECHO_MSG}	"execute the following command as root:"
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"  echo '${PORTNAME}_enable=\"YES\"' >>/etc/rc.conf"
	@${ECHO_MSG}	""

.include <bsd.port.mk>

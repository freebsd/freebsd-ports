# New ports collection makefile for:	vhcp
# Date created:        20 June 2009
# Whom:            Maxim Ignatenko
#
# $FreeBSD$
#

PORTNAME=	vhcp
PORTVERSION=	1.7g2
CATEGORIES=	net-p2p www
MASTER_SITES=	SF/${PORTNAME}/PHP%205.x/1.7g
DISTNAME=	vhcp_v${PORTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Verlihub control panel

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_PHP=	mysql gd
NO_BUILD=	YES
WANT_PHP_WEB=	YES
DEFAULT_PHP_VER=	5
VHCPDIR?=	www/vhcp
SUB_FILES=	pkg-message
SUB_LIST+=	VHCPDIR=${VHCPDIR}
PLIST=	${WRKDIR}/pkg-plist

pre-install:
	@if [ -f ${WRKSRC}/config.php ]; then \
	   	${MV} ${WRKSRC}/config.php ${WRKSRC}/config.php.dist ; fi
	@cd ${WRKSRC} && \
		${ECHO_CMD} "@unexec if cmp -s %D/${VHCPDIR}/config.php.dist \
		%D/${VHCPDIR}/config.php; then \
		${RM} -f %D/${VHCPDIR}/config.php; fi" > ${PLIST} && \
		${FIND} -s * -type f | \
		${SED} -e 's|^|${VHCPDIR}/|g' >> ${PLIST} && \
		${ECHO_CMD} "@exec if [ ! -f %D/${VHCPDIR}/config.php ] ; then \
		${CP} -p %D/${VHCPDIR}/config.php.dist \
		%D/${VHCPDIR}/config.php; fi" >> ${PLIST} && \
		${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${VHCPDIR}/|g' >> ${PLIST} && \
		${ECHO_CMD} @dirrm ${VHCPDIR} >> ${PLIST}

do-install:
	-@${MKDIR} ${PREFIX}/${VHCPDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${VHCPDIR}
	@${CHMOD} 755 ${PREFIX}/${VHCPDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${VHCPDIR}
	if [ ! -f ${PREFIX}/${VHCPDIR}/config.php ]; then \
		${CP} ${PREFIX}/${VHCPDIR}/config.php.dist \
		${PREFIX}/${VHCPDIR}/config.php ; \
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

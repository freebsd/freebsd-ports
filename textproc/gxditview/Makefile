# New ports collection makefile for:   gxditview
# Date created:                24 June 1998
# Whom:                        Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	gxditview
PORTVERSION=	1.16.1
CATEGORIES=	textproc
DISTFILES=	# none

MAINTAINER=	dom@myrddin.demon.co.uk

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_IMAKE=	yes
MAN1=		gxditview.1

GXDVSRC?=	/usr/src/contrib/groff/xditview

do-extract:
	@if [ ! -d ${GXDVSRC} ]; then \
		${ECHO} "You need the gxditview source in"; \
		${ECHO} "${GXDVSRC}"; \
		${ECHO} "to build this port."; \
	exit 1; \
	fi
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	${CP} -rp ${GXDVSRC}/* ${WRKSRC}

.include <bsd.port.mk>

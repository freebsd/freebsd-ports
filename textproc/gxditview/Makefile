# New ports collection makefile for:   gxditview
# Version required:     1.10
# Date created:                24 June 1998
# Whom:                        Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id$
#

# Same version as the contrib groff sources...
DISTNAME=      gxditview-1.10
CATEGORIES=    textproc
DISTFILES=     # none

MAINTAINER=     dom@myrddin.demon.co.uk

USE_IMAKE=     yes
WRKSRC=                ${WRKDIR}/${DISTNAME}

GXDVSRC?=      /usr/src/contrib/groff/xditview

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

# New ports collection makefile for:   gxditview
# Date created:                24 June 1998
# Whom:                        Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	gxditview
CATEGORIES=	textproc
DISTFILES=	# none

MAINTAINER=	ru@FreeBSD.org
COMMENT=	An X11 based previewer for groff output

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_IMAKE=	yes
MAN1=		gxditview.1

.if exists(/usr/src/contrib/groff/src/xditview)
GXDVSRC=	/usr/src/contrib/groff/src/xditview
GXDVVERSION!=	cat /usr/src/contrib/groff/VERSION
GXDVREVISION!=	sed -e 's/^0$$//' -e 's/^[1-9].*$$/.&/' /usr/src/contrib/groff/REVISION
PORTVERSION=	${GXDVVERSION}${GXDVREVISION}
.else
GXDVSRC=	/usr/src/contrib/groff/xditview
PORTVERSION=	1.16.1
.endif

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

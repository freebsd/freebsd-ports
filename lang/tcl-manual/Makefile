# New ports collection makefile for:   tcl-manual
# Date created:        13 December 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	tcl-manual
PORTVERSION=	2001.12.19
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcl
DISTFILES=	tcl8.3.4.html.tar.gz tcl8.4a3.html.tar.gz

MAINTAINER=	edwin@mavetju.org

USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	@${RM} ${WRKDIR}/tcl8.3.4/html/UserCmd/*.orig
	@${RM} ${WRKDIR}/tcl8.4a3/html/UserCmd/*.orig
	@${REINPLACE_CMD} -e 's|tcl\.h|tcl8.3/tcl.h|g' \
		${WRKDIR}/tcl8.3.4/html/TclLib/*
	@${REINPLACE_CMD} -e 's|tk\.h|tk8.3/tk.h|g' \
		${WRKDIR}/tcl8.3.4/html/TkLib/*
	@${REINPLACE_CMD} -e 's|tcl\.h|tcl8.4/tcl.h|g' \
		${WRKDIR}/tcl8.4a3/html/TclLib/*
	@${REINPLACE_CMD} -e 's|tk\.h|tk8.4/tk.h|g' \
		${WRKDIR}/tcl8.4a3/html/TkLib/*
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${MKDIR} ${PREFIX}/share/doc/tcl83
	${MKDIR} ${PREFIX}/share/doc/tcl84
	${CP} -R ${WRKDIR}/tcl8.4a3/html/* ${PREFIX}/share/doc/tcl84
	${CP} -R ${WRKDIR}/tcl8.3.4/html/* ${PREFIX}/share/doc/tcl83

.include <bsd.port.mk>

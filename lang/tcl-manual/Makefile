# New ports collection makefile for:   tcl-manual
# Date created:        13 December 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	tcl-manual
PORTVERSION=	20041118
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcl
DISTFILES=	tcl8.3.5-html.tar.gz tcl8.4.7-html.tar.gz tcl8.5a1-html.tar.gz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Documentation for TCL (Tool Command Language)

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete
	@${REINPLACE_CMD} -e 's|tcl\.h|tcl8.3/tcl.h|g' \
		${WRKDIR}/tcl8.3.5/html/TclLib/*
	@${REINPLACE_CMD} -e 's|tk\.h|tk8.3/tk.h|g' \
		${WRKDIR}/tcl8.3.5/html/TkLib/*
	@${REINPLACE_CMD} -e 's|tcl\.h|tcl8.4/tcl.h|g' \
		${WRKDIR}/tcl8.4.7/html/TclLib/*
	@${REINPLACE_CMD} -e 's|tk\.h|tk8.4/tk.h|g' \
		${WRKDIR}/tcl8.4.7/html/TkLib/*
	@${REINPLACE_CMD} -e 's|tcl\.h|tcl8.5/tcl.h|g' \
		${WRKDIR}/tcl8.5a1/html/TclLib/*
	@${REINPLACE_CMD} -e 's|tk\.h|tk8.5/tk.h|g' \
		${WRKDIR}/tcl8.5a1/html/TkLib/*
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${MKDIR} ${PREFIX}/share/doc/tcl83
	${MKDIR} ${PREFIX}/share/doc/tcl84
	${MKDIR} ${PREFIX}/share/doc/tcl85
	${CP} -R ${WRKDIR}/tcl8.5a1/html/* ${PREFIX}/share/doc/tcl85
	${CP} -R ${WRKDIR}/tcl8.4.7/html/* ${PREFIX}/share/doc/tcl84
	${CP} -R ${WRKDIR}/tcl8.3.5/html/* ${PREFIX}/share/doc/tcl83

.include <bsd.port.mk>

# New ports collection makefile for:	tcltutor
# Date created:		11 November 2000
# Whom:			Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	tcltutor
PORTVERSION=	2.b.4
PORTREVISION=	2
CATEGORIES=	lang tk84 tcl84
MASTER_SITES=	http://www.msen.com/~clif/
DISTNAME=	Tutor2b4

MAINTAINER=	edwin@mavetju.org
COMMENT=	A Tcl/Tk based tutorial for Tcl

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		tkman:${PORTSDIR}/misc/tkman

WRKSRC=		${WRKDIR}/TclTutor
NO_BUILD=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/tcltutor/TclTutor/}

post-install:
	${INSTALL_DATA} ${WRKSRC}/help.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/about.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>

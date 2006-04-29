# New ports collection makefile for:	tcltutor
# Date created:		11 November 2000
# Whom:			Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	tcltutor
PORTVERSION=	2.b.4
PORTREVISION=	4
CATEGORIES=	lang tk84 tcl84
MASTER_SITES=	http://www.msen.com/~clif/
DISTNAME=	Tutor2b4

MAINTAINER=	edwin@mavetju.org
COMMENT=	A Tcl/Tk based tutorial for Tcl

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		tkman:${PORTSDIR}/misc/tkman

REINPLACE_ARGS=	-i ""
WRKSRC=		${WRKDIR}/TclTutor
NO_BUILD=	yes
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/tcltutor/TclTutor/}

post-patch:
	@${REINPLACE_CMD} -e "s|wish|wish8.4|" \
		-e "s|scaler.tcl|${PREFIX}/bin/scaler.tcl|" \
		-e "s|htmllib.tcl|${PREFIX}/bin/htmllib.tcl|" \
		-e "s|set Tutor(lessonHome).*|set Tutor(lessonHome) \"${DOCSDIR}/\"|" \
		${WRKSRC}/TclTutor.tcl

post-install:
	${INSTALL_DATA} ${WRKSRC}/help.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/about.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	xspeakfree
# Date created:			08 Nov 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	xspeakfree
PORTVERSION=	0.8.2
CATEGORIES=	mbone net audio
MASTER_SITES=	http://www.liquidx.org/distfiles/

MAINTAINER=	tlp@liquidx.org
COMMENT=	Tcl/Tk (wish) frontend to Speak Freely

RUN_DEPENDS=	${LOCALBASE}/bin/wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/bin/sfmike:${PORTSDIR}/mbone/speak_freely \

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

PORTDOCS=	BUGS HISTORY INSTALL LICENSE README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|wish|wish8.4|' ${WRKSRC}/bin/xspeakfree

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xspeakfree ${PREFIX}/bin/xspeakfree
	${MKDIR} ${PREFIX}/lib/xspeakfree
	${INSTALL_DATA} ${WRKSRC}/lib/xspeakfree/* ${PREFIX}/lib/xspeakfree
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor

.include <bsd.port.mk>

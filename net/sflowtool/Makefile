# New ports collection makefile for:  sflowtool
# Date created:        21 Mar 2006
# Whom:                Gregory Edigarov <greg@bestnet.kharkov.ua>
#
# $FreeBSD$
#

PORTNAME=	sflowtool
PORTVERSION=	3.18
CATEGORIES=	net
MASTER_SITES=	http://www.inmon.com/bin/

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	This is a sFlow capture and sFlow-to-NetFlow conversion tool

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/sflowtool
PORTDOCS=	README
PORTEXAMPLES=	README ipTopTalkers ipTrafficMatrix sflowRRDChart.cgi \
		sflowRRDLoad sflowenable

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
. for f in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/scripts/$f ${EXAMPLESDIR}/
. endfor
.endif

.include <bsd.port.mk>

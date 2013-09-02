# New ports collection makefile for:	wikicalc
# Date created:		June 24, 2007
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wikicalc
PORTVERSION=	1.0
CATEGORIES=	www math
MASTER_SITES=	http://www.peapodcast.com/sgi/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,-,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	An Open Source Wiki-Spreadsheet

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	setup.sh

post-extract:
	@${RM} -f ${WRKSRC}/gpl.txt

post-patch:
	${REINPLACE_CMD} 's,/usr/bin/perl,${PERL5} -I${DATADIR},' ${WRKSRC}/*.pl

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
	${FIND} . -type f -a ! -name \*.pl -a ! -name \*.bak | \
		${XARGS} -J % ${INSTALL_DATA} % ${DATADIR}/$${i}; \
	${FIND} . -type f -a -name \*.pl | \
		${XARGS} -J % ${INSTALL_SCRIPT} % ${DATADIR}/$${i}; \
	${INSTALL_SCRIPT} ${WRKDIR}/setup.sh ${DATADIR}

.include <bsd.port.mk>

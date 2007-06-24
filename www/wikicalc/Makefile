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

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	setup.sh
SUB_LIST=	DATADIR=${DATADIR}

post-extract:
	@${RM} -f ${WRKSRC}/gpl.txt

post-patch:
	${REINPLACE_CMD} 's,/usr/bin/perl,${PERL5} -I${DATADIR},' ${WRKSRC}/*.pl

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && \
	for i in `${FIND} . -type f -a ! -name \*.pl -a ! -name \*.bak`; do \
		${INSTALL_DATA} $${i} ${DATADIR}/$${i}; \
	done; \
	for i in `${FIND} . -type f -a -name \*.pl`; do \
		${INSTALL_SCRIPT} $${i} ${DATADIR}/$${i}; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/setup.sh ${DATADIR}

.include <bsd.port.mk>

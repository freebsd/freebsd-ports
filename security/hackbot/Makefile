# New ports collection makefile for:   hackbot
# Date created:        Mon Jan 13 15:44:35 GMT 2003
# Whom:                mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	hackbot
PORTVERSION=	2.21
CATEGORIES=	security
MASTER_SITES=	http://ws.obit.nl/hackbot/
EXTRACT_SUFX=   .tgz

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A host exploration tool and bannergrabber

USE_REINPLACE=	YES
USE_PERL5=	YES
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/etc/|${DATADIR}/hackbot/|' ${WRKSRC}/hackbot.pl

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/google.db ${DATADIR}/google.db
	${INSTALL_DATA} ${WRKSRC}/fingerprint.db ${DATADIR}/fingerprint.db
	${INSTALL_DATA} ${WRKSRC}/cgi.db ${DATADIR}/cgi.db
	${INSTALL_SCRIPT} ${WRKSRC}/hackbot.pl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hackbot.1.gz ${PREFIX}/man/man1/

MAN1=	hackbot.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>

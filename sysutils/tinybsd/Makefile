# New ports collection makefile for:	tinybsd
# Date created:		11 July 2005
# Whom:			Jean Milanez Melo <jmelo@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	tinybsd
PORTVERSION=	0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tinybsd.org/download/

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	Shell script to build embedded systems based on FreeBSD

NO_BUILD=	yes
SUB_FILES=	pkg-message

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DATADIR}
	${CP} -Rp ${WRKSRC}/conf ${DATADIR}/
	${SED} "s|/usr/local|${PREFIX}|g" ${WRKSRC}/tinybsd > ${PREFIX}/bin/tinybsd
	${CHMOD} 555 ${PREFIX}/bin/tinybsd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for: 	dhttpd
# Date created:				24 June 2002
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dhttpd
PORTVERSION=	1.02a
CATEGORIES=	www
MASTER_SITES=	http://uts.cc.utexas.edu/~foxx/dhttpd/	\
		http://ccca.nctu.edu.tw/~gslin/Software/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimal secure webserver. Fast and efficient, no cgi-bin support

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-1.02-4
BUILD_WRKSRC=	${WRKSRC}/src

MAN1=		dhttpd.1

STARTUP_SCRIPT=	${PORTNAME}.sh

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/src/config.hh
	@${SED} -e "s,%%PREFIX%%,${PREFIX}," ${FILESDIR}/${STARTUP_SCRIPT} > ${WRKSRC}/${STARTUP_SCRIPT}

do-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d

.include <bsd.port.mk>

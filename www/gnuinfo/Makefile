# New ports collection makefile for:	gnuinfo
# Date created:		Tue Oct 12 00:02:04 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	gnuinfo
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	http://www.wohnheim.uni-ulm.de/allerlei/

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	CGI program to convert GNU .info files into html

NO_WRKSUBDIR=	yes

###
# Use these options for Apache:
###
CGIDIR=		${PREFIX}/share/apache/cgi-bin

do-install:
	${MKDIR} ${CGIDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gnuinfo ${CGIDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/gnuinfo.local ${FILESDIR}/gnuinfo.X11R6 ${CGIDIR}

.include <bsd.port.mk>

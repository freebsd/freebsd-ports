# New ports collection makefile for:	tei-guidelines
# Date created:				29 April 2002
# Whom:	      				Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	p4
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Guidelines2/
PKGNAMESUFFIX=	-guidelines
DISTNAME=	p4html

MAINTAINER=	henrik.motakef@web.de

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
INSTDIR=	${PREFIX}/share/doc/tei/p4

do-install:
	@${MKDIR} ${INSTDIR}
	@${MKDIR} ${INSTDIR}/Status
	@${INSTALL_MAN} ${WRKSRC}/*.html ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.css ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.gif ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/*.jpg ${INSTDIR}
	@${INSTALL_MAN} ${WRKSRC}/Status/* ${INSTDIR}/Status

.include <bsd.port.mk>

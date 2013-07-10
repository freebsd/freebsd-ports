# Created by: Jeroen Hogeveen <albast@xs4all.nl>
# $FreeBSD$

PORTNAME=	ml
PORTVERSION=	3.4
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	X11 IMAP client

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USES=		imake motif
USE_XORG=	ice sm x11 xext xmu xp xt

pre-configure:
	@${ECHO_MSG} "===>  Building c-client"
	@( cd ${WRKSRC}/../imap-4; make bsi )
	@( cd ${WRKSRC}; ${RM} -f makeproto )

.include <bsd.port.mk>

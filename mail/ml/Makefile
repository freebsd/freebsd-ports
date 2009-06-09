# New ports collection makefile for:	YACL
# Date created:		15 March 1998
# Whom:			Jeroen Hogeveen <albast@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	ml
PORTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	An X11 IMAP client

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xext xmu xp xt
USE_MOTIF=	yes

pre-configure:
	@${ECHO_MSG} "===>  Building c-client"
	@( cd ${WRKSRC}/../imap-4; make bsi )
	@( cd ${WRKSRC}; ${RM} -f makeproto )

.include <bsd.port.mk>

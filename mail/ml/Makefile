# New ports collection makefile for:	YACL
# Date created:		15 March 1998
# Whom:			Jeroen Hogeveen <albast@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	ml
PORTVERSION=	3.4
CATEGORIES=	mail
# mastersite disappeared in October 2003
MASTER_SITES=	# http://ftp.rge.com/pub/mail/ml/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 IMAP client

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_IMAKE=	yes
USE_MOTIF=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile"
.endif

pre-configure:
	@${ECHO_MSG} "===>  Building c-client"
	@( cd ${WRKSRC}/../imap-4; make bsi )
	@( cd ${WRKSRC}; ${RM} -f makeproto )

.include <bsd.port.post.mk>

# New ports collection makefile for:	YACL
# Date created:		15 March 1998
# Whom:			Jeroen Hogeveen <albast@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=		ml
PORTVERSION= 		3.4
CATEGORIES=		mail
MASTER_SITES=		http://people.netscape.com/max/ml/

MAINTAINER=		albast@xs4all.nl

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_IMAKE=		yes
REQUIRES_MOTIF=		yes
NO_INSTALL_MANPAGES=	yes

pre-configure:
	@${ECHO_MSG} "===>  Building c-client"
	@( cd ${WRKSRC}/../imap-4; make bsi )
	@( cd ${WRKSRC}; ${RM} -f makeproto )

.include <bsd.port.mk>

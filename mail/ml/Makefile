# New ports collection makefile for:	YACL
# Version required:     3.4
# Date created:		15 March 1998
# Whom:			Jeroen Hogeveen <albast@xs4all.nl>
#
# $Id: Makefile,v 1.1.1.1 1999/01/11 05:13:09 steve Exp $
#

DISTNAME=		ml-3.4
CATEGORIES=		mail
MASTER_SITES=		http://people.netscape.com/max/ml/

MAINTAINER=		albast@xs4all.nl

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_IMAKE=		yes
REQUIRES_MOTIF=		yes
NO_INSTALL_MANPAGES=	yes

pre-configure:
	@echo "===>  Building c-client"
	@( cd ${WRKSRC}/../imap-4; make bsi )
	@( cd ${WRKSRC}; ${RM} -f makeproto )

.include <bsd.port.mk>

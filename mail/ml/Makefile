# New ports collection makefile for:	YACL
# Version required:     3.3-new
# Date created:		15 March 1998
# Whom:			Jeroen Hogeveen <albast@xs4all.nl>
#
# $Id$
#

DISTNAME=		ml-3.3.new
PKGNAME=		ml-3.3
CATEGORIES=		mail
MASTER_SITES=		http://people.netscape.com/max/ml/

MAINTAINER=		albast@xs4all.nl

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_IMAKE=		yes
REQUIRES_MOTIF=		yes

pre-configure:
	@echo "===>  Building c-client"
	@( cd ${WRKSRC}/../imap-4; make bsf )
	@( cd ${WRKSRC}; ${RM} -f makeproto )

do-install:
	@( cd ${WRKSRC}; make install )

.include <bsd.port.mk>

# New ports collection makefile for:	bash
# Version required:     1.14.7
# Date created:		21 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.25 1997/06/26 06:23:23 fenner Exp $
#

DISTNAME=       bash-1.14.7
CATEGORIES=	shells
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	obrien@NUXI.com

NO_LATEST_LINK=	yes
WRKSRC=         ${WRKDIR}/${DISTNAME}
# Don't compress manpages or .so not works.

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/bash.info ${PREFIX}/info/dir

.include <bsd.port.mk>

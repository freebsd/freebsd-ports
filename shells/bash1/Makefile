# ex:ts=8
# New ports collection makefile for:	bash
# Version required:     1.14.7
# Date created:		21 August 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.27 1998/08/13 21:30:06 obrien Exp $
#

DISTNAME=       bash-1.14.7
CATEGORIES=	shells
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	bash

MAINTAINER=	obrien@FreeBSD.org

NO_LATEST_LINK=	yes
WRKSRC=         ${WRKDIR}/${DISTNAME}
# Don't compress manpages or .so not works.
NOMANCOMPRESS=	yes
MAN1=		bash.1 bash_builtins.1

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/bash.info ${PREFIX}/info/dir

.include <bsd.port.mk>

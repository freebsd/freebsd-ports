# New ports collection makefile for:  jargon
# Version required:	4.0.0
# Date created: 	11 July 1998
# Whom:			moeding
#
# $Id$
#

DISTNAME=	jarg400.info
PKGNAME=	jargon-4.0.0
CATEGORIES=	misc
MASTER_SITES=	http://sagan.earthspace.net/jargon/
EXTRACT_SUFX=	.gz

MAINTAINER=	s.moeding@ndh.net

NO_WRKSUBDIR=	YES
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/jargon.info
NO_BUILD=	YES

do-install:
	@${INSTALL_DATA} ${WRKSRC}/jargon.info ${PREFIX}/info

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	@install-info \
	  --section="Miscellaneous" \
	  --entry="* Jargon: (jargon).             The hacker's dictionary." \
	  ${PREFIX}/info/jargon.info ${PREFIX}/info/dir

.include <bsd.port.mk>

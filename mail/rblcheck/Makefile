# New ports collection makefile for:	rblcheck
# Version required:	1.2
# Date created:		28 January 1998
# Whom:			itojun@itojun.org
#
# $Id$
#

DISTNAME=	rblcheck-1.2
CATEGORIES=	mail
MASTER_SITES=	http://www.xnet.com/%7Eemarshal/rblcheck/

MAINTAINER=	itojun@itojun.org

NO_PATCH=	yes
NO_CONFIGURE=	yes
DOCS=		BUGS CHANGES CREDITS INSTALL PLATFORMS TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	dst=${PREFIX}/share/doc/rblcheck; \
	${MKDIR} $$dst; \
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$i $$dst; \
	done
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	rblcheck
# Version required:	1.2
# Date created:		28 January 1998
# Whom:			itojun@itojun.org
#
# $Id: Makefile,v 1.1.1.1 1998/01/30 04:52:11 itojun Exp $
#

DISTNAME=	rblcheck-1.2
CATEGORIES=	mail
MASTER_SITES=	http://www.xnet.com/%7Eemarshal/rblcheck/

MAINTAINER=	itojun@itojun.org

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

# New ports collection makefile for:	rblcheck
# Date created:		28 January 1998
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	rblcheck
PORTVERSION= 	1.4
CATEGORIES=	mail
MASTER_SITES=	http://download.sourceforge.net/rblcheck/ \
		http://www.xnet.com/%7Eemarshal/rblcheck/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://rblcheck.sourceforge.net/

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

# New ports collection makefile for:	bsdsar
# Date created:				12 June 2001
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	bsdsar
PORTVERSION=	0.10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.googlebit.com/bsdsar/

MAINTAINER=	leeym@leeym.com

NO_BUILD=	yes

do-install:
.for file in bsdsar bsdsar_gather
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in CHANGELOG README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

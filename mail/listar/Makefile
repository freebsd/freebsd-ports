# New ports collection makefile for:	listar
# Date created:		09 Apr 2000
# Whom:			Peter Losher <plosher@wwiv.com>
#
# $FreeBSD$
#

PORTNAME=	listar
PORTVERSION=	0.129a
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.listar.org/pub/listar/

MAINTAINER=	plosher@wwiv.com

USE_GMAKE=	yes

NO_PACKAGE=	"Requires listar uid"
WRKSRC=		${WRKDIR}/${DISTNAME}/src

pre-patch:

	@ ${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

pre-install:

	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@ ${MKDIR} ${PREFIX}/listar
	@ ${CP} -R ${WRKDIR}/${DISTNAME}/* ${PREFIX}/listar
	@ ${RM} -R ${PREFIX}/listar/src/
	@ ${RM} -R ${PREFIX}/listar/debian/
	@ ${CHOWN} -R listar:listar ${PREFIX}/listar/*

post-install:

	@${ECHO_MSG} "---------------------------------------------------"
	@${ECHO_MSG} "- Thank You for installing the Listar Listserver  -"
	@${ECHO_MSG} "- package.  Please read the documentation located -"
	@${ECHO_MSG} "- in ${PREFIX}/listar/, or online at:            -"
	@${ECHO_MSG} "-                                                 -"
	@${ECHO_MSG} "- http://www.listar.org/                          -"
	@${ECHO_MSG} "-                                                 -"
	@${ECHO_MSG} "- -The Listar Developers                          -"
	@${ECHO_MSG} "---------------------------------------------------"

.include <bsd.port.mk>

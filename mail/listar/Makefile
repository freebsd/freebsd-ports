# New ports collection makefile for:	listar
# Date created:		09 Apr 2000
# Whom:			Peter Losher <plosher@wwiv.com>
#
# $FreeBSD$
#

PORTNAME=	listar
PORTVERSION=	1.0.0.b1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.listar.org/pub/listar/snapshots/tar/
DISTFILES=	listar-1.0.0-snap20010225${EXTRACT_SUFX}

MAINTAINER=	plosher@wwiv.com

FORBIDDEN=	"Remotely exploitable buffer overflow by submitted mail; superceded by mail/ecartis"

USE_GMAKE=	yes

NO_PACKAGE=	"Requires listar uid"
WRKSRC=		${WRKDIR}/listar-1.0.0/src

pre-patch:

	@ ${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

pre-install:

	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@ ${MKDIR} ${PREFIX}/${PORTNAME}
	@ ${CP} -R ${WRKDIR}/${PORTNAME}-1.0.0/* ${PREFIX}/listar
	@ ${RM} -R ${PREFIX}/${PORTNAME}/src/
	@ ${RM} -R ${PREFIX}/${PORTNAME}/debian/
	@ ${CHOWN} -R listar:listar ${PREFIX}/${PORTNAME}/*

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

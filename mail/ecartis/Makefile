# New ports collection makefile for: ecartis
# Date created:                20 January 2002
# Whom:                        Trish Lynch <trish@bsdunix.net>
#
# $FreeBSD$
#

PORTNAME=	ecartis
PORTVERSION=	1.0.0b
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ecartis.org/pub/ecartis/snapshots/tar/
DISTNAME=	ecartis-1.0.0-snap20020118

MAINTAINER=	trish@bsdunix.net

USE_GMAKE=	yes

NO_PACKAGE=	"Requires ecartis uid"
WRKSRC=		${WRKDIR}/ecartis-1.0.0/src

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -R ${WRKDIR}/${PORTNAME}-1.0.0/* ${PREFIX}/ecartis
	@${RM} -R ${PREFIX}/${PORTNAME}/src/
	@${RM} -R ${PREFIX}/${PORTNAME}/debian/
	@${CHOWN} -R ecartis:ecartis ${PREFIX}/${PORTNAME}/*

post-install:
	@${ECHO_MSG} "---------------------------------------------------"
	@${ECHO_MSG} "- Thank You for installing the Ecartis Listserver -"
	@${ECHO_MSG} "- package.  Please read the documentation located -"
	@${ECHO_MSG} "- in ${PREFIX}/ecartis/, or online at:            -"
	@${ECHO_MSG} "-                                                 -"
	@${ECHO_MSG} "- http://www.listar.org/                          -"
	@${ECHO_MSG} "-                                                 -"
	@${ECHO_MSG} "- -The Listar/Ecartis Developers                  -"
	@${ECHO_MSG} "---------------------------------------------------"

.include <bsd.port.mk>

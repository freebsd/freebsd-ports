# New ports collection makefile for: ecartis
# Date created:                20 January 2002
# Whom:                        Trish Lynch <trish@bsdunix.net>
#
# $FreeBSD$
#

PORTNAME=	ecartis
PORTVERSION=	1.0.0.s20040426
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ecartis.org/pub/ecartis/snapshots/tar/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.s/-snap/}

MAINTAINER=	trish@bsdunix.net
COMMENT=	The Ecartis Listserver \ Mailing List Manager

USE_GMAKE=	yes

NO_PACKAGE=	"Requires ecartis uid"
IS_INTERACTIVE=	"Stops to ask to create ecartis user/group"
WRKSRC=		${WRKDIR}/ecartis-1.0.0/src

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dist ${WRKSRC}/Makefile

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -R ${WRKDIR}/${PORTNAME}-1.0.0/* ${PREFIX}/ecartis
	@${RM} -R ${PREFIX}/${PORTNAME}/src/
	@${RM} -R ${PREFIX}/${PORTNAME}/debian/
	@${RM} ${PREFIX}/${PORTNAME}/ecartis.dsp ${PREFIX}/${PORTNAME}/ecartis.dsw
	@${CHOWN} -R ecartis:ecartis ${PREFIX}/${PORTNAME}/*

post-install:
	@${ECHO_MSG} "---------------------------------------------------"
	@${ECHO_MSG} "- Thank You for installing the Ecartis Listserver -"
	@${ECHO_MSG} "- package.  Please read the documentation located -"
	@${ECHO_MSG} "- in ${PREFIX}/ecartis/, or online at:            -"
	@${ECHO_MSG} "-                                                 -"
	@${ECHO_MSG} "- http://www.ecartis.org/                         -"
	@${ECHO_MSG} "-                                                 -"
	@${ECHO_MSG} "- -The Ecartis Developers                         -"
	@${ECHO_MSG} "---------------------------------------------------"

.include <bsd.port.mk>

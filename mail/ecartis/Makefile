# Created by: Trish Lynch <trish@bsdunix.net>
# $FreeBSD$

PORTNAME=	ecartis
PORTVERSION=	1.0.0.s20060813
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://conducive.net/tarballs/ \
		http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.s/-snap/}

MAINTAINER=	jtrigg@spamcop.net
COMMENT=	The Ecartis Listserver \ Mailing List Manager

USES=		gmake

NO_PACKAGE=	Requires ecartis uid
IS_INTERACTIVE=	"Stops to ask to create ecartis user/group"
WRKSRC=		${WRKDIR}/ecartis-1.0.0/src

NO_STAGE=	yes
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

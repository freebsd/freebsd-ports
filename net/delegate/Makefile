# New ports collection makefile for:	DeleGate
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	delegate
PORTVERSION=	5.9.13
CATEGORIES=	net www japanese
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/DeleGate/
DISTNAME=	delegate5.9.13

MAINTAINER=	max@FreeBSD.org
NO_PACKAGE=	"Insecure program."
MAKE_ENV=	PATH=$${PATH}:.
IS_INTERACTIVE=	YES

pre-fetch:
.if !defined(FORCE_BUILD) || ${FORCE_BUILD}!="YES"
	@${ECHO} "*********************************************************************"
	@${ECHO} "*   WARNING!     WARNING!     WARNING!     WARNING!     WARNING!    *"
	@${ECHO} "* This program has know security problems which may allow a remote  *"
	@${ECHO} "* attacker to take control of your machine.                         *"
	@${ECHO} "* See FreeBSD security advisory 00:04 for more information.         *"
	@${ECHO} "*                                                                   *"
	@${ECHO} "* It is strongly recommended that you avoid using this program.     *"
	@${ECHO} "*                                                                   *"
	@${ECHO} "* If you would like to use this program despite the danger, run     *"
	@${ECHO} "* make with ``FORCE_BUILD=YES''                                     *"
	@${ECHO} "*   WARNING!     WARNING!     WARNING!     WARNING!     WARNING!    *"
	@${ECHO} "*********************************************************************"
	@${FALSE}
.else
	@${ECHO} "*********************************************************************"
	@${ECHO} "*   WARNING!     WARNING!     WARNING!     WARNING!     WARNING!    *"
	@${ECHO} "* You have chosen to build an insecure program.                     *"
	@${ECHO} "* This program has know security problems which may allow a remote  *"
	@${ECHO} "* attacker to take control of your machine.                         *"
	@${ECHO} "* See FreeBSD security advisory 00:04 for more information.         *"
	@${ECHO} "*********************************************************************"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/share/examples/delegate
	${INSTALL_DATA} ${FILESDIR}/delegated.sh \
	   ${PREFIX}/share/examples/delegate
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.txt \
	  ${PREFIX}/share/doc/delegate
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

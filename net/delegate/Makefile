# New ports collection makefile for:	DeleGate
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	delegate
PORTVERSION=	7.1.2
CATEGORIES=	net www
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/ \
		ftp://ftp.etl.go.jp/pub/DeleGate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	max@FreeBSD.org

NO_PACKAGE=	"Insecure program."
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
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.htm \
	  ${PREFIX}/share/doc/delegate
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

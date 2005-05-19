# New ports collection makefile for:	DeleGate
# Date created:			26 Jan 1997
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	delegate
PORTVERSION=	8.11.3
CATEGORIES=	net www
MASTER_SITES=	ftp://www.delegate.org/pub/DeleGate/ \
		ftp://ftp.delegate.org/pub/DeleGate/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	gioria@FreeBSD.org
COMMENT=	General purpose TCP/IP proxy system

USE_BZIP2=	yes
IS_INTERACTIVE=	YES
PORTDOCS=	Manual.htm tutor-jp.htm tutor-en.htm
PLIST_FILES=	sbin/delegated etc/rc.d/delegated.sh-dist

pre-everything::
.if !defined(FORCE_BUILD) || ${FORCE_BUILD}!="YES"
	@${ECHO_MSG} "*********************************************************************"
	@${ECHO_MSG} "*   WARNING!     WARNING!     WARNING!     WARNING!     WARNING!    *"
	@${ECHO_MSG} "* This program has known security problems which may allow a remote *"
	@${ECHO_MSG} "* attacker to take control of your machine.                         *"
	@${ECHO_MSG} "* See FreeBSD security advisory 00:04 for more information.         *"
	@${ECHO_MSG} "*                                                                   *"
	@${ECHO_MSG} "* It is strongly recommended that you avoid using this program.     *"
	@${ECHO_MSG} "*                                                                   *"
	@${ECHO_MSG} "* If you would like to use this program despite the danger, run     *"
	@${ECHO_MSG} "* make with \`\`FORCE_BUILD=YES''                                     *"
	@${ECHO_MSG} "*   WARNING!     WARNING!     WARNING!     WARNING!     WARNING!    *"
	@${ECHO_MSG} "*********************************************************************"
	@${FALSE}
.else
	@${ECHO_MSG} "*********************************************************************"
	@${ECHO_MSG} "*   WARNING!     WARNING!     WARNING!     WARNING!     WARNING!    *"
	@${ECHO_MSG} "* You have chosen to build an insecure program.                     *"
	@${ECHO_MSG} "* This program has known security problems which may allow a remote *"
	@${ECHO_MSG} "* attacker to take control of your machine.                         *"
	@${ECHO_MSG} "* See FreeBSD security advisory 00:04 for more information.         *"
	@${ECHO_MSG} "*********************************************************************"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/delegated.sh \
	   ${PREFIX}/etc/rc.d/delegated.sh-dist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection Makefile for:   be_agent
# Date created:        20 May 2005
# Whom:                Tony Shadwick <numbski@hksilver.net>
#
# $FreeBSD$
#

PORTNAME=	be_agent
PORTVERSION=	5.046
CATEGORIES=	sysutils
MASTER_SITES=  #
DISTNAME=	nls_agnt_262592
EXTRACT_SUFX=	.tar

MAINTAINER=	numbski@hksilver.net
COMMENT=	VERITAS Backup Exec (tm) UNIX Agent

DOWNLOAD_URL=	http://seer.support.veritas.com/docs/262592.htm

USE_LINUX=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NO_INSTALL_MANPAGES=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	be-agent.sh
PLIST_FILES=	bin/agent.be \
		etc/be-agent.cfg.sample

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.  Please access\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
Click \"Download Now\"\, and agree to the license agreement.  Please place\n\
the downloaded ${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}.\n
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/common/agent.linux24 ${PREFIX}/bin/agent.be
	@${CAT} ${PKGMESSAGE} ${WRKDIR}/english/agent.cfg \
		${FILESDIR}/config_example >> ${WRKDIR}/be-agent.cfg.sample
	@${INSTALL_DATA} ${WRKDIR}/be-agent.cfg.sample ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

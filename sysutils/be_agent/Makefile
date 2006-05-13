# New ports collection Makefile for:   be_agent
# Date created:        20 May 2005
# Whom:                Tony Shadwick <numbski@hksilver.net>
#
# $FreeBSD$
#

PORTNAME=	be_agent
PORTVERSION=	5.046
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.support.veritas.com/pub/support/products/Backup_Exec_for_WindowsNT/ \
		http://www.numbski.net/downloads/
DISTNAME=	nls_agnt_262592
EXTRACT_SUFX=	.tar

MAINTAINER=	numbski@hksilver.net
COMMENT=	VERITAS Backup Exec (tm) UNIX Agent

RUN_DEPENDS=	${LINUXBASE}/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NO_INSTALL_MANPAGES=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	be-agent.sh
PLIST_FILES=	bin/agent.be \
		etc/be-agent.cfg.sample

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/common/agent.linux24 ${PREFIX}/bin/agent.be
	@${CAT} ${PKGMESSAGE} ${WRKDIR}/english/agent.cfg \
		${FILESDIR}/config_example >> ${WRKDIR}/be-agent.cfg.sample
	@${INSTALL_DATA} ${WRKDIR}/be-agent.cfg.sample ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

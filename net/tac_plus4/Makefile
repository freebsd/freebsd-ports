# New ports collection makefile for:	tac_plus
# Version required:	2.1
# Date created:		4 Mar 1997
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $Id: Makefile,v 1.3 1998/01/16 04:06:17 jseger Exp $
#

DISTNAME=	tac_plus.2.1
PKGNAME=	tac_plus-2.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftpeng.cisco.com/pub/tacacs/old/
EXTRACT_SUFX=	.tar

MAINTAINER=	igor@zynaps.ru

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
ALL_TARGET=	tac_plus
MAN8=		tac_plus.8
EXTRA_PATCH=	patch-ba

# To change the text displayed when users are prompted to enter
# a username, set appropriately TAC_CHANGE_PROMPT variable.
.if defined(TAC_CHANGE_PROMPT) && ${TAC_CHANGE_PROMPT} == YES
pre-patch:
	@${CP} ${FILESDIR}/${EXTRA_PATCH} ${PATCHDIR}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${PREFIX}/man/man8/tac_plus.8
	${INSTALL_DATA} ${FILESDIR}/tac_plus.conf.example ${PREFIX}/etc/
	@if [ ! -f ${PREFIX}/etc/rc.d/tac_plus.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tac_plus.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/tac_plus.sh; \
		echo "[ -x ${PREFIX}/sbin/tac_plus -a -f ${PREFIX}/etc/tac_plus.conf ] && ${PREFIX}/sbin/tac_plus -C ${PREFIX}/etc/tac_plus.conf && echo -n ' tac_plus'" >> ${PREFIX}/etc/rc.d/tac_plus.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/tac_plus.sh; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
.endif

pre-clean:
	@${RM} -f ${PATCHDIR}/${EXTRA_PATCH}

.include <bsd.port.mk>

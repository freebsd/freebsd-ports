# New ports collection makefile for:	tac_plus
# Version required:	2.1
# Date created:		4 Mar 1997
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $Id$
#

DISTNAME=	tac_plus.2.1
PKGNAME=	tac_plus-2.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftpeng.cisco.com/pub/tacacs/
EXTRACT_SUFX=	.tar

MAINTAINER=	igor@zynaps.ru

EXTRACT_BEFORE_ARGS=	-C ${WRKDIR} -xf
ALL_TARGET=	tac_plus
MAN8=		tac_plus.8

post-patch:
	@${MV} -f ${WRKSRC}/tac_plus.1 ${WRKSRC}/tac_plus.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${FILESDIR}/tacacs.conf.example ${PREFIX}/etc/
	@if [ ! -f ${PREFIX}/etc/rc.d/tac_plus.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tac_plus.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/tac_plus.sh; \
		echo "[ -x ${PREFIX}/sbin/tac_plus -a -f ${PREFIX}/etc/tac_plus.conf ] && ${PREFIX}/sbin/tac_plus -C ${PREFIX}/etc/tacacs.conf && echo -n ' tac_plus'" >> ${PREFIX}/etc/rc.d/tac_plus.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/tac_plus.sh; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	tac_plus
# Date created:		4 Mar 1997
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	tac_plus
PORTVERSION=	F4.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp-eng.cisco.com/pub/tacacs/
DISTNAME=	tac_plus.F4.0.4.alpha
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	andreas@FreeBSD.org

ALL_TARGET=	tac_plus
MAN1=		tac_plus.1

# To change the text displayed when users are prompted to enter
# a username, set appropriately TAC_CHANGE_PROMPT variable.
.if defined(TAC_CHANGE_PROMPT) && ${TAC_CHANGE_PROMPT} == YES
EXTRA_PATCHES=	${FILESDIR}/patch-ba
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${PREFIX}/man/man1/tac_plus.1
	${INSTALL_DATA} ${FILESDIR}/tac_plus.conf.example ${PREFIX}/etc/
	@if [ ! -f ${PREFIX}/etc/rc.d/tac_plus.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tac_plus.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tac_plus.sh ${PREFIX}/etc/rc.d/tac_plus.sh; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/users_guide ${PREFIX}/share/doc/tac_plus
	${INSTALL_SCRIPT} ${WRKSRC}/convert.pl ${PREFIX}/share/doc/tac_plus
.endif

post-install:
	strip ${PREFIX}/sbin/tac_plus

.include <bsd.port.mk>

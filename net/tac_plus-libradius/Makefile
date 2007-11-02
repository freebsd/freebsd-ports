# New ports collection makefile for:	tac_plus-libradius
# Date created:				January, 21th. 2002
# Whom:	      				Martin Mersberger <gremlin@portal-to-web.de>
# $FreeBSD$
#

PORTNAME=	tac_plus-libradius
PORTVERSION=	5.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.portal-to-web.de/tacacs/ \
		http://www.santel.lu/projects/ldap-tacacs/
DISTFILES=	tac_plus.F5.0.0.alpha.tar.gz \
		tac_plus_radius.tgz

MAINTAINER=	gremlin@portal-to-web.de
COMMENT=	The www.gazi.edu.tr tacacs+ Daemon with pam and libradius support

WRKPREFIX=	tac_plus.F5.0.0.alpha
WRKSRC=		${WRKDIR}/${WRKPREFIX}/

USE_OPENSSL=	yes

ALL_TARGET=	tac_plus
MAN1=		tac_plus.1

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${PREFIX}/man/man1/tac_plus.1
	@${MKDIR} ${PREFIX}/etc/tac_plus
	${INSTALL_DATA} ${WRKSRC}/tac_plus.cfg ${PREFIX}/etc/tac_plus/
	${INSTALL_DATA} ${WRKSRC}/radius.example ${PREFIX}/etc/tac_plus/
	@if [ ! -f ${PREFIX}/etc/rc.d/tac_plus.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tac_plus.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tac_plus.sh ${PREFIX}/etc/rc.d/tac_plus.sh.sample; \
	fi

.include <bsd.port.post.mk>

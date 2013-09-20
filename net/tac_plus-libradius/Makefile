# Created by: Martin Mersberger <gremlin@portal-to-web.de>
# $FreeBSD$

PORTNAME=	tac_plus-libradius
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.portal-to-web.de/tacacs/ \
		http://www.santel.lu/projects/ldap-tacacs/
DISTFILES=	tac_plus.F5.0.0.alpha.tar.gz \
		tac_plus_radius.tgz

MAINTAINER=	gremlin@portal-to-web.de
COMMENT=	The www.gazi.edu.tr tacacs+ Daemon with pam and libradius support

USE_RC_SUBR=	tac_plus

CONFLICTS=	ru-tac+ia-[0-9]* tac_plus-[0-9]*

WRKPREFIX=	tac_plus.F5.0.0.alpha
WRKSRC=		${WRKDIR}/${WRKPREFIX}/

USE_OPENSSL=	yes

ALL_TARGET=	tac_plus
MAN1=		tac_plus.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tac_plus ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/tac_plus.1 ${PREFIX}/man/man1/tac_plus.1
	@${MKDIR} ${PREFIX}/etc/tac_plus
	@${INSTALL_DATA} -m 640 ${WRKSRC}/tac_plus.cfg ${PREFIX}/etc/tac_plus/tac_plus.cfg.sample
	@${INSTALL_DATA} -m 640 ${WRKSRC}/radius.example ${PREFIX}/etc/tac_plus/radius.cfg.sample

.include <bsd.port.post.mk>

# New ports collection makefile for:    GNU finger
# Date created:         20 June 1996
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gnu-finger
PORTVERSION=	1.37
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	finger
DISTNAME=	finger-1.37

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	GNU version of finger

HAS_CONFIGURE=	yes
INSTALL_TARGET=	server

post-install:
	${MKDIR} ${PREFIX}/etc/fingerdir
	${MKDIR} ${PREFIX}/etc/rc.d
	@${CP} ${WRKSRC}/support/ttylocs ${PREFIX}/etc/fingerdir/ttylocs.sample
	@${CP} ${FILESDIR}/clients.sample ${PREFIX}/etc/fingerdir/clients.sample
	@${INSTALL} ${COPY} -m 744 -o root ${FILESDIR}/fingerd.sh.sample ${PREFIX}/etc/rc.d/fingerd.sh.sample
	@${ECHO_CMD} "GNU.finger.server.hostname" > ${PREFIX}/etc/fingerdir/serverhost.sample
	@${ECHO_CMD} "mail.spool.server.hostname" > ${PREFIX}/etc/fingerdir/mailhost.sample

.include <bsd.port.mk>

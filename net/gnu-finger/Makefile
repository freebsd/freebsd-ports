# New ports collection makefile for:    GNU finger
# Version required:     1.37
# Date created:         20 June 1996
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.6 1997/01/06 07:24:39 max Exp $
#

DISTNAME=       finger-1.37
PKGNAME=        gnu-finger-1.37
CATEGORIES=     net
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	finger

MAINTAINER=     sanpei@yy.cs.keio.ac.jp

HAS_CONFIGURE=	yes
INSTALL_TARGET= server

post-install:
	${MKDIR} ${PREFIX}/etc/fingerdir
	${MKDIR} ${PREFIX}/etc/rc.d
	@${CP} ${WRKSRC}/support/ttylocs ${PREFIX}/etc/fingerdir/ttylocs.sample
	@${CP} ${FILESDIR}/clients.sample ${PREFIX}/etc/fingerdir/clients.sample
	@${INSTALL} ${COPY} -m 744 -o root ${FILESDIR}/fingerd.sh.sample ${PREFIX}/etc/rc.d/fingerd.sh.sample
	@echo "GNU.finger.server.hotname" > ${PREFIX}/etc/fingerdir/serverhost.sample
	@echo "mail.spool.server.hostname" > ${PREFIX}/etc/fingerdir/mailhost.sample

.include <bsd.port.mk>

# New ports collection makefile for:    GNU finger
# Version required:     1.37
# Date created:         20 June 1996
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.3 1996/07/12 11:01:27 asami Exp $
#

DISTNAME=       finger-1.37
PKGNAME=        gnu-finger-1.37
CATEGORIES=     net
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=     sanpei@yy.cs.keio.ac.jp

HAS_CONFIGURE=	yes
INSTALL_TARGET= server

post-install:
	mkdir -p ${PREFIX}/etc/fingerdir
	mkdir -p ${PREFIX}/etc/rc.d
	@cp ${WRKSRC}/support/ttylocs ${PREFIX}/etc/fingerdir/ttylocs.sample
	@cp ${FILESDIR}/clients.sample ${PREFIX}/etc/fingerdir/clients.sample
	@install -c -m 744 -o root ${FILESDIR}/start.fingerd.sh.sample ${PREFIX}/etc/rc.d/start.fingerd.sh.sample
	@echo "GNU.finger.server.hotname" > ${PREFIX}/etc/fingerdir/serverhost.sample
	@echo "mail.spool.server.hostname" > ${PREFIX}/etc/fingerdir/mailhost.sample

.include <bsd.port.mk>

# New ports collection makefile for:    flexbackup
# Version required:     0.9.7
# Date created:         Tue Oct 19 22:46:36 MST 1999
# Whom:                 John Reynolds <jreynold@primenet.com>
#
# $FreeBSD$
#

DISTNAME=       flexbackup-0.9.7
CATEGORIES=     sysutils
MASTER_SITES=   http://www.bluecherry.net/~edwinh/flexbackup/tarball/ \
		http://members.home.com/edwinh/flexbackup/tarball/ \
		http://metalab.unc.edu/pub/linux/system/backup/

MAINTAINER=     jreynold@primenet.com

RUN_DEPENDS=    afio:${PORTSDIR}/sysutils/afio \
		buffer:${PORTSDIR}/misc/buffer

NO_BUILD  = yes
USE_PERL5 = yes

post-configure:
	@cp ${WRKSRC}/flexbackup.conf ${WRKSRC}/flexbackup.conf.sample
	@cp ${WRKSRC}/README ${WRKSRC}/flexbackup.README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flexbackup ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/flexbackup
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf.sample ${PREFIX}/share/flexbackup
	${INSTALL_DATA} ${WRKSRC}/flexbackup.README ${PREFIX}/share/flexbackup

post-install:
	@cat ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

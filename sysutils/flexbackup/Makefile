# New ports collection makefile for:    flexbackup
# Date created:         Wed Nov  3 17:58:26 MST 1999
# Whom:                 John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	flexbackup
PORTVERSION=	0.9.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.edwinh.org/flexbackup/tarball/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/backup

MAINTAINER=	johnjen@reynoldsnet.org

RUN_DEPENDS=	afio:${PORTSDIR}/sysutils/afio \
		buffer:${PORTSDIR}/misc/buffer

NO_BUILD=	yes
USE_PERL5=	yes

post-configure:
	@${CP} ${WRKSRC}/flexbackup.conf ${WRKSRC}/flexbackup.conf.sample
	@${CP} ${WRKSRC}/README ${WRKSRC}/flexbackup.README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flexbackup ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/flexbackup
	${INSTALL_DATA} ${WRKSRC}/flexbackup.conf.sample ${PREFIX}/share/doc/flexbackup
	${INSTALL_DATA} ${WRKSRC}/flexbackup.README ${PREFIX}/share/doc/flexbackup

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's:%%PREFIX%%:${PREFIX}:g'

.include <bsd.port.mk>

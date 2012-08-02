# New ports collection makefile for:	asr-manpages
# Date created:		April 15, 2003
# Whom:			Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asr-manpages
PORTVERSION=	20000406
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fjoe
DISTNAME=	asr.pages

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	alt.sysadmin.recovery man page distribution

NO_BUILD=	yes
MAN1=		c.1 lart.1 rtfm.1 slave.1 sysadmin.1 think.1 whack.1
MAN2=		people.2
MAN3=		chastise.3
MAN5=		normality.5
MAN8=		bosskill.8 ctluser.8 guru.8 knife.8 luser.8 nuke.8 pmsd.8

do-install:
	@${INSTALL_MAN} ${WRKDIR}/bosskill.8	${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKDIR}/c.1		${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/chastise.3	${PREFIX}/man/man3
	@${INSTALL_MAN} ${WRKDIR}/ctluser.8	${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKDIR}/guru.8	${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKDIR}/knife.8	${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKDIR}/lart.1m	${PREFIX}/man/man1/lart.1
	@${INSTALL_MAN} ${WRKDIR}/luser.8	${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKDIR}/normality.5	${PREFIX}/man/man5
	@${INSTALL_MAN} ${WRKDIR}/nuke.8	${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKDIR}/people.2	${PREFIX}/man/man2
	@${INSTALL_MAN} ${WRKDIR}/pmsd.8	${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKDIR}/rtfm.1	${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/slave.1	${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/sysadmin.1	${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/think.1	${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/whack.1	${PREFIX}/man/man1

.include <bsd.port.mk>

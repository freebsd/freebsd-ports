PORTNAME=	asr-manpages
PORTVERSION=	20000406
CATEGORIES=	misc
MASTER_SITES=	LOCAL/fjoe
DISTNAME=	asr.pages

MAINTAINER=	ports@FreeBSD.org
COMMENT=	alt.sysadmin.recovery man page distribution

NO_BUILD=	yes

do-install:
	${INSTALL_MAN} ${WRKDIR}/bosskill.8	${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/c.1		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/chastise.3	${STAGEDIR}${PREFIX}/man/man3
	${INSTALL_MAN} ${WRKDIR}/ctluser.8	${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/guru.8		${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/knife.8	${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/lart.1m	${STAGEDIR}${PREFIX}/man/man1/lart.1
	${INSTALL_MAN} ${WRKDIR}/luser.8	${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/normality.5	${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKDIR}/nuke.8		${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/people.2	${STAGEDIR}${PREFIX}/man/man2
	${INSTALL_MAN} ${WRKDIR}/pmsd.8		${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/rtfm.1		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/slave.1	${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/sysadmin.1	${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/think.1	${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/whack.1	${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

# ports collection makefile for:	pm-lib
# Date created:				14 November 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	pm-lib
PORTVERSION=	20010728
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-2001.0728

MAINTAINER=	ishmael27@home.com

RUN_DEPENDS=	procmail:${PORTSDIR}/mail/procmail

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

LIBS=		pm-jaaddr.rc pm-jabup.rc pm-jacookie.rc \
		pm-jacookie1.rc pm-jacron.rc pm-jadaemon.rc pm-jadate.rc \
		pm-jadate1.rc pm-jadate2.rc pm-jadate3.rc pm-jadate4.rc \
		pm-jadate5.rc pm-jadup.rc pm-jaempty.rc pm-jafrom.rc \
		pm-jafwd.rc pm-jalist.rc pm-jamime-decode.rc \
		pm-jamime-kill.rc pm-jamime-save.rc pm-jamime.rc \
		pm-janetmind.rc pm-janslookup.rc pm-jaorig.rc pm-japing.rc \
		pm-japop3.rc pm-jarandf.rc pm-jasrv-check.rc \
		pm-jasrv-daemon.rc pm-jasrv-err.rc pm-jasrv-from.rc \
		pm-jasrv-msg.rc pm-jasrv-multi.rc pm-jasrv-req.rc \
		pm-jasrv-send.rc pm-jasrv.rc pm-jastore.rc pm-jasubject.rc \
		pm-jatime.rc pm-jaube.rc pm-jaube1.rc pm-javac.rc pm-javar.rc
DOCS=		README.html README.txt index.html pm-lib-body.html \
		pm-lib-toc.html pm-lib.html pm-lib.txt

do-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
.for i in ${LIBS}
	${INSTALL_DATA} ${WRKSRC}/lib/${i} ${PREFIX}/share/${PORTNAME}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lib/ChangeLog ${PREFIX}/share/doc/${PORTNAME}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>

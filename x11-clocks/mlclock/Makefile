# New ports collection makefile for:   mlclock
# Version required:    1.0
# Date created:        December 05 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1998/09/22 22:32:08 asami Exp $
#

DISTNAME=	mlclock
PKGNAME=	mlclock-1.0
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/

MAINTAINER=	nacai@iname.com

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/mlclock

.if !defined(KANJIMODE)
pre-patch:
	@${ECHO_MSG} "Japanese Kanji mode disabled."
	@${ECHO_MSG} "Use 'make -DKANJIMODE' when compiling if you want the Japanese"
	@${ECHO_MSG} "kanji mode enabled."
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-aa
.endif

.include <bsd.port.mk>

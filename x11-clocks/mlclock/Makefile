# New ports collection makefile for:   mlclock
# Version required:    1.0
# Date created:        December 05 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	mlclock
PKGNAME=	mlclock-1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.bioele.nuee.nagoya-u.ac.jp/member/tak/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

pre-patch:
.if !defined(KANJIMODE)
	@${ECHO_MSG} "Japanese Kanji mode disabled....."
	@${CP} ${FILESDIR}/patch-aa ${PATCHDIR}
.endif

.include <bsd.port.mk>

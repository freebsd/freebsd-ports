# Created by: Per Otterstr=F6m <pelle@fukt.bth.se>
# $FreeBSD$

PORTNAME=	wmclock
PORTVERSION=	1.0.14
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.bluestop.org/wmclock/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable clock applet for Window Maker

USE_IMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_XORG=	xpm
MAN1=		wmclock.1
PLIST_FILES=	bin/wmclock
WMCLOCK_LANG?=	english

pre-configure:
	(cd ${WRKSRC}; \
	${WRKSRC}/configure --lang ${WMCLOCK_LANG} > /dev/null )
	@${ECHO_MSG} "You can choose which language to use by "
	@${ECHO_MSG} "setting the WMCLOCK_LANG variable to one "
	@${ECHO_MSG} "of the following values (default: english):"
	@${ECHO_MSG}
	@${ECHO_MSG} "breton croatian czech danish dutch english"
	@${ECHO_MSG} "french french2 german hungarian indonesian"
	@${ECHO_MSG} "italian norwegian polish portuguese russian"
	@${ECHO_MSG} "slovene spanish swedish ukrainian"
	@${ECHO_MSG} "Example: \"make WMCLOCK_LANG=french\""
	@${ECHO_MSG}

.include <bsd.port.mk>

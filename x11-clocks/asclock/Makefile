# New ports collection makefile for:   asclock
# Version required:    1.0
# Date created:        20 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.6 1999/01/12 16:50:21 vanilla Exp $
#

DISTNAME=	asclock
PKGNAME=	asclock-1.0
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=		applications
EXTRACT_SUFX=	.tgz

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
MAN1=		asclock.1

pre-configure:
	(cd ${WRKSRC}; \
	${ECHO} ${ASCLOCK_LANG} | ${WRKSRC}/configure > /dev/null)
	@${ECHO_MSG} "*****************  NOTE  *****************"
	@${ECHO_MSG} "*                                        *"
	@${ECHO_MSG} "*  You can choose languages for asclock. *"
	@${ECHO_MSG} "* 1) engligh [DEFAULT]                   *"
	@${ECHO_MSG} "* 2) german                              *"
	@${ECHO_MSG} "* 3) portuguese                          *"
	@${ECHO_MSG} "* 4) dutch                               *"
	@${ECHO_MSG} "* 5) norwegian                           *"
	@${ECHO_MSG} "* 6) italian                             *"
	@${ECHO_MSG} "* 7) swedish                             *"
	@${ECHO_MSG} "* 8) spanish                             *"
	@${ECHO_MSG} "* 9) hungarian                           *"
	@${ECHO_MSG} "* 0) breton                              *"
	@${ECHO_MSG} "* a) french                              *"
	@${ECHO_MSG} "* b) czech                               *"
	@${ECHO_MSG} "*                                        *"
	@${ECHO_MSG} "* Specify the number you want when make. *"
	@${ECHO_MSG} "* Example: \" make ASCLOCK_LANG=1 \"       *"
	@${ECHO_MSG} "******************************************"

.include <bsd.port.mk>

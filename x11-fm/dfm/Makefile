# New ports collection makefile for:	dfm
# Version required:			0.9.10
# Date created:				25 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.9 1998/12/07 20:46:38 billf Exp $
#

DISTNAME=	dfm-0.9.10
CATEGORIES=	x11-fm
MASTER_SITES=	http://www-c.informatik.uni-hannover.de/~kaiser/dfm/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

# depends on xforms
ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/dfm

MAN1=		dfm.1

do-configure:
	@ cd ${WRKSRC}; ./config

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/dfm ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/dfm.1x ${PREFIX}/man/man1/dfm.1
	@ ${MKDIR} ${PREFIX}/share/dfm
	@ ${MKDIR} ${PREFIX}/share/dfm/backgrounds
	@ ${INSTALL_DATA} ${WRKSRC}/share/backgrounds/*.xpm ${PREFIX}/share/dfm/backgrounds
	@ ${MKDIR} ${PREFIX}/share/dfm/icons
	@ ${INSTALL_DATA} ${WRKSRC}/share/icons/*.xpm ${PREFIX}/share/dfm/icons
	@ ${MKDIR} ${PREFIX}/share/dfm/icons/Appicons
	@ ${INSTALL_DATA} ${WRKSRC}/share/icons/Appicons/*.xpm ${PREFIX}/share/dfm/icons/Appicons
	@ ${MKDIR} ${PREFIX}/share/dfm/icons/Moreicons
	@ ${INSTALL_DATA} ${WRKSRC}/share/icons/Moreicons/*.xpm ${PREFIX}/share/dfm/icons/Moreicons
	@ ${MKDIR} ${PREFIX}/share/examples/dfm
	@ ${INSTALL_DATA} ${WRKSRC}/extensions/dfmext_local ${PREFIX}/share/examples/dfm/dfmext.sample.local
	@ ${INSTALL_DATA} ${WRKSRC}/extensions/dfmext_normal ${PREFIX}/share/examples/dfm/dfmext.sample.normal
	@ ${INSTALL_DATA} ${WRKSRC}/extensions/dfmext_user ${PREFIX}/share/examples/dfm/dfmext.sample.user
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/dfm
.for file in ANNOUNCE BUGS COPYING COPYRIGHT CREDITS HELP.ERROR NO_WARRANTY README START TESTED TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/dfm
.endfor
.endif

.include <bsd.port.mk>

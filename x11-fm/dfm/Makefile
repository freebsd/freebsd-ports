# New ports collection makefile for:	dfm
# Version required:			0.9.10
# Date created:				25 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	dfm-0.99.1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www-c.informatik.uni-hannover.de/~kaiser/dfm/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"		

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/dfm

MAN1=		dfm.1

post-install:
	@ ${MV} ${PREFIX}/man/man1/dfm.1x ${PREFIX}/man/man1/dfm.1
	@ ${MKDIR} ${PREFIX}/share/examples/dfm
	@ ${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_local ${PREFIX}/share/examples/dfm/dfmext.sample.local
	@ ${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_normal ${PREFIX}/share/examples/dfm/dfmext.sample.normal
	@ ${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_user ${PREFIX}/share/examples/dfm/dfmext.sample.user
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/dfm
.for file in ANNOUNCE BUGS COPYING COPYRIGHT CREDITS ChangeLog DOWNLOAD HELP.ERROR NO_WARRANTY README START TESTED TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/dfm
.endfor
.endif

.include <bsd.port.mk>

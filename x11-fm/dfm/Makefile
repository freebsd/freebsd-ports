# New ports collection makefile for:	dfm
# Version required:			0.9.10
# Date created:				25 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.10 1999/01/07 08:19:53 simokawa Exp $
#

DISTNAME=	dfm-0.99.1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www-c.informatik.uni-hannover.de/~kaiser/dfm/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext \
		gmodule12.1:${PORTSDIR}/devel/glib12 \
		glib12.1:${PORTSDIR}/devel/glib12 \
		gdk12.1:${PORTSDIR}/x11-toolkits/gtk12 \
		gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${X11BASE}/include" GTK_CONFIG="${X11BASE}/bin/gtk12-config"

# depends on xforms
ONLY_FOR_ARCHS=	i386

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

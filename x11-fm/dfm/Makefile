# New ports collection makefile for:	dfm
# Date created:				25 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	dfm
PORTVERSION= 	0.99.6
CATEGORIES=	x11-fm
MASTER_SITES=	http://linux.tucows.com/files/x11/file/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"		
CONFIGURE_ARGS=	--disable-gtktest --disable-imlibtest

MAN1=		dfm.1x

DFM_DOCS=	ANNOUNCE BUGS COPYRIGHT CREDITS ChangeLog DOWNLOAD HELP.ERROR \
		NO_WARRANTY README START TESTED TODO

post-install:
	@${MKDIR} ${PREFIX}/share/examples/dfm
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_local ${PREFIX}/share/examples/dfm/dfmext.sample.local
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_normal ${PREFIX}/share/examples/dfm/dfmext.sample.normal
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_user ${PREFIX}/share/examples/dfm/dfmext.sample.user
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dfm
.for file in ${DFM_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/dfm
.endfor
.endif

.include <bsd.port.mk>

# Created by: mandree@FreeBSD.org
# $FreeBSD$

PORTNAME=	pidgin-skype
PORTVERSION=	0.0.0.664
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	LOCAL/mandree
DISTFILES=	pidgin-skype-svn-r${PORTVERSION:E}.tar.xz

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Plugin to use Skype chat from Pidgin (with Skype running)

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:net-im/pidgin \
    ${LOCALBASE}/bin/skype:net-im/skype
RUN_DEPENDS=	pidgin:net-im/pidgin \
    ${LOCALBASE}/bin/skype:net-im/skype

USES=		gmake pkgconfig tar:xz
USE_GNOME=	glib20

# this is a local target to build a tarball
build-tarball: ${DISTFILES}
${DISTFILES}:
	${RM} -rf ${WRKSRC}
	svn export -r${PORTVERSION:E} \
	    http://skype4pidgin.googlecode.com/svn/trunk/ ${WRKSRC}
	tar -C ${WRKSRC}/.. -cvf - ${WRKSRC:T} | ${XZ_CMD} -vvc >${DISTFILES} || \
	    { ${RM} -f ${DISTFILES} ; exit 1 ; }

upload-tarball: build-tarball
	scp ${DISTFILES} freefall.freebsd.org:public_distfiles/

mycflags=	-shared -fPIC -DPIC \
		-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libpurple \
		-I${LOCALBASE}/include/pidgin \
		-I${LOCALBASE}/include/glib-2.0 \
		-I${LOCALBASE}/lib/glib-2.0/include \
		-DPURPLE_PLUGINS
mylibs=		-lpthread

# DBUS: No DBUS here, does not work with Skype 2.1 beta
# NLS: While the build works and enables translations,
# the upstream translations and .pot file are woefully out of date.
#OPTIONS_DEFINE=	NLS

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
mycflags+=	-DENABLE_NLS
mylibs+=	-L${LOCALBASE}/lib -lintl
USES+=		gettext
PLIST_SUB+=	NLS=""

post-patch:
	${REINPLACE_CMD} 's/#undef ENABLE_NLS//' ${WRKSRC}/libskype.c
.else
PLIST_SUB+=	NLS="@comment "
.endif

do-build:
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} ${mycflags} \
			-o libskype.so libskype.c ${mylibs}
.if ${PORT_OPTIONS:MNLS}
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} -C ${BUILD_WRKSRC} locales
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/purple-2
	${INSTALL_PROGRAM} ${WRKSRC}/libskype.so ${STAGEDIR}${PREFIX}/lib/purple-2
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/emotes/skype
	${INSTALL_DATA} ${WRKSRC}/theme ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/emotes/skype
.for i in 16 22 48
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/protocols/${i}
	${INSTALL_DATA} ${WRKSRC}/icons/${i}/skypeout.png \
	    ${WRKSRC}/icons/${i}/skype.png \
	    ${STAGEDIR}${PREFIX}/share/pixmaps/pidgin/protocols/${i}/
.endfor
.if ${PORT_OPTIONS:MNLS}
.for i in cs de en_AU es fr hu it ja mk nb pl pt pt_BR ru
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/
	${INSTALL_DATA} ${WRKSRC}/po/${i}.mo ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/skype4pidgin.mo
.endfor
.endif

.include <bsd.port.mk>

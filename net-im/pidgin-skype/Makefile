# New ports collection makefile for:	pidgin-skype
# Date created:				2010-12-19
# Whom:					mandree@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pidgin-skype
PORTVERSION=	0.0.0.605
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mandree
DISTFILES=	pidgin-skype-svn-r${PORTVERSION:E}.tar.xz

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Plugin to use Skype chat from Pidgin (with Skype running)

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:${PORTSDIR}/net-im/pidgin \
    ${LOCALBASE}/bin/skype:${PORTSDIR}/net/skype
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin \
    ${LOCALBASE}/bin/skype:${PORTSDIR}/net/skype

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_GNOME=	glib20
USE_XZ=		yes

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

mycflags=	-shared -fPIC -DPIC ${PTHREAD_CFLAGS} \
		-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libpurple \
		-I${LOCALBASE}/include/pidgin \
		-I${LOCALBASE}/include/glib-2.0 \
		-DPURPLE_PLUGINS
mylibs=		${PTHREAD_LIBS}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${mycflags} \
			-o libskype.so libskype.c ${mylibs}

do-install:
	${MKDIR} ${PREFIX}/lib/purple-2
	${INSTALL_DATA} ${WRKSRC}/libskype.so ${PREFIX}/lib/purple-2
	${MKDIR} ${PREFIX}/share/pixmaps/pidgin/emotes/skype
	${INSTALL_DATA} ${WRKSRC}/theme ${PREFIX}/share/pixmaps/pidgin/emotes/skype
.for i in 16 22 48
	${MKDIR} ${PREFIX}/share/pixmaps/pidgin/protocols/${i}
	${INSTALL_DATA} ${WRKSRC}/icons/${i}/skypeout.png \
	    ${WRKSRC}/icons/${i}/skype.png \
	    ${PREFIX}/share/pixmaps/pidgin/protocols/${i}/
.endfor

.include <bsd.port.mk>

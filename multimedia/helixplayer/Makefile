# New ports collection makefile for:	hxplay
# Date created:		21 May 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	hxplay
PORTVERSION=	1.0.7
CATEGORIES=	multimedia
MASTER_SITES=	https://helixcommunity.org/download.php/1950/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	The Helix Community's open source media player

LIB_DEPENDS=	theora.[1-9]:${PORTSDIR}/multimedia/libtheora		\
		esd.2:${PORTSDIR}/audio/esound	\
		png:${PORTSDIR}/graphics/png	\
		jpeg:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_DOS2UNIX=	player/app/plugin/unix.pcf
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/HelixPlayer/lib

SUB_FILES=	pkg-message

CF2FIX=		gcc.cf freebsd.cf freebsd-5.0-i586.cf freebsd-4.0-i386.cf	\
		freebsd-4.0-i586.cf freebsd-6.0-i586.cf freebsd-7.0-i586.cf

EXCLUDE=	common/import datatype/image/jpg/import \
		common/util/getopt.c common/util/md5*   \
		datatype/image/png/import               \
		build/BIF/build.bif
EXTRACT_AFTER_ARGS=| ${TAR} -xf - ${EXCLUDE:S,^,--exclude ${DISTNAME}/,}

pre-patch:
	${LN} ${WRKSRC}/build/umakecf/freebsd-6.0-i586.cf			\
		${WRKSRC}/build/umakecf/freebsd-7.0-i586.cf
	# Add support for AudioOutLinux
	${LN} ${WRKSRC}/audio/device/linux2.pcf					\
		${WRKSRC}/audio/device/freebsd.pcf

pre-configure:
.if !defined(WITH_DEBUG)
	${REINPLACE_CMD} -e 's|# project.AddBuildOption("release")|project.AddBuildOption("release")|'	\
		${WRKSRC}/build/umakecf/freebsd.cf
	${REINPLACE_CMD} -e 's|gtk_release|gtk_release -t release|'		\
		${WRKSRC}/Makefile
.endif
.for cf in ${CF2FIX}
	${REINPLACE_CMD} -e "s|%%CC%%|${CC}|;s|%%CFLAGS%%|${CFLAGS}|"		\
		-e "s|%%CXX%%|${CXX}|;s|%%CXXFLAGS%%|${CXXFLAGS}|"		\
		-e "s|/usr/X11R6|${X11BASE}|;s|/usr/local|${LOCALBASE}|"	\
		-e "s|%%PREFIX%%|${PREFIX}|"					\
		-e "s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|"			\
		-e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|"			\
		${WRKSRC}/build/umakecf/${cf}
.endfor
	${SED} -e "s|/usr/local|${LOCALBASE}|" < ${FILESDIR}/buildrc		\
		> ${WRKSRC}/buildrc
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|"				\
		${WRKSRC}/player/app/gtk/hxplay

post-build:
	@if ! ${TAIL} "${WRKSRC}/build.out" | ${GREP} -qF ', 0 of' ; \
	then	\
		${ECHO_MSG} ==================================================; \
		${ECHO_MSG} Something failed, please examine the log file;	\
		${ECHO_MSG} ${WRKSRC}/build.out;				\
		${ECHO_MSG} ==================================================; \
		${FALSE};	\
	fi

do-install:
	${MKDIR} ${PREFIX}/HelixPlayer
	${RM} -rf ${WRKSRC}/player/installer/archive/temp/Bin
	${CP} -Rp ${WRKSRC}/player/installer/archive/temp/* \
		${PREFIX}/HelixPlayer/
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/HelixPlayer
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${PREFIX}/HelixPlayer/hxplay.bin
.endif
	${LN} -sf ${PREFIX}/HelixPlayer/hxplay ${PREFIX}/bin/hxplay
	${LN} -sf ${PREFIX}/HelixPlayer/lib/libgtkhx.so	\
		${PREFIX}/HelixPlayer/lib/libgtkhx.so.0
	${MKDIR} ${DESKTOPDIR}
	${LN} -sf ${PREFIX}/HelixPlayer/share/hxplay.desktop ${DESKTOPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

BROKEN=		fails to install

.if ${ARCH}==ia64
BROKEN=		does not compile on ${ARCH} due to coredump
.endif

.include <bsd.port.post.mk>

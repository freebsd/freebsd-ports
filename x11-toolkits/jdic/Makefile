# New ports collection makefile for:	jdic
# Date created:		Tue 26 dec 2006 10:46:02 GMT
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	jdic
PORTVERSION=	20061102
CATEGORIES=	x11-toolkits java
MASTER_SITES=	https://jdic.dev.java.net/files/documents/880/43269/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	JDesktop Integration Components

# USE_GMAKE conflicts with USE_ANT
BUILD_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
#		nspr4.1:${PORTSDIR}/devel/nspr

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	the required com.sun.jnlp is part of jawaws.jar, only installed on i386

USE_ZIP=	yes
USE_ANT=	yes
USE_XLIB=	yes
USE_GNOME=	pkgconfig # libgnome
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_LDCONFIG=	yes
# Do not build mozembed: it requires Gecko_SDK and XULRunner, which is
# broken ATM - see <http://developer.mozilla.org/en/docs/Gecko_SDK>.
#USE_GECKO=	firefox seamonkey mozilla

#ALL_TARGET=	buildall
ALL_TARGET=	buildtray
WRKSRC=		${WRKDIR}/src
BUILD_WRKSRC=	${WRKSRC}/jdic	# Remove to build all
MAKE_ENV=	CLASSPATH="${JAVA_HOME}/jre/lib/javaws.jar"
#MAKE_ENV=	MOZILLA_DIST="`${GECKO_CONFIG} --prefix`/lib/${GECKO}"	\
#		GECKO_SDK="${GECKO_SDK}"

MKFILES=	jni mozilla
DIST_DIR=	${WRKSRC}/jdic/dist/${OPSYS:L}

PLIST_FILES=	%%JAVAJARDIR%%/jdic.jar	\
		lib/libtray.so		\
		lib/libtray.so.0

.include <bsd.port.pre.mk>

pre-configure:
.for mk in ${MKFILES}
	${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g;	\
		s|/usr/local|${LOCALBASE}|g'		\
		${WRKSRC}/jdic/src/unix/native/${mk}/Makefile
.endfor

do-install:
	${INSTALL_DATA}	${DIST_DIR}/jdic.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${DIST_DIR}/libtray.so ${PREFIX}/lib/libtray.so.0
	${LN} -sf ${PREFIX}/lib/libtray.so.0 ${PREFIX}/lib/libtray.so

.if defined(MAINTAINER_MODE)
regression-test:	install
	(cd ${WRKSRC}/jdic/demo/Tray &&				\
	javac -cp "${JAVAJARDIR}/jdic.jar:." Tray.java &&	\
	java -cp "${JAVAJARDIR}/jdic.jar:." Tray)
.endif

#.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>

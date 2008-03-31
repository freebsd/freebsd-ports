# New ports collection makefile for:	Democracy
# Date created:		30 November 2006
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	Miro
PORTVERSION=	1.2.1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.osuosl.org/pub/pculture.org/miro/src/	\
		http://ftp.osuosl.org/pub/pculture.org/miro/src/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A video player to get internet TV broadcasts

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex				\
		update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine			\
		fame-0.9:${PORTSDIR}/multimedia/libfame			\
		boost_python.4:${PORTSDIR}/devel/boost-python
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick			\
		${PYTHON_SITELIBDIR}/dbus/glib.py:${PORTSDIR}/devel/py-dbus	\
		${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb	\
		${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite23

USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20 gtk20 pygnomeextras
USE_GECKO=	firefox seamonkey mozilla
USE_GSTREAMER=	python
INSTALLS_EGGINFO=	yes

BUILD_WRKSRC=	${WRKSRC}/platform/gtk-x11
MAKE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}"

DATADIR=	${PREFIX}/share/${PORTNAME:L}
PLIST_SUB=	VER=${PORTVERSION} PYTHON_VER=${_PYTHON_VERSION}	\
		DESKTOPDIR=share/applications
PYDISTUTILS_PKGNAME=	${PORTNAME:L}

MAN1=		miro.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

pre-configure:
.for pyscr in setup.py platform/resources.py
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|'		\
		-e 's|/usr/X11R6|${X11BASE}|g'				\
		-e 's|/usr/share|${PREFIX}/share|g'			\
		-e 's|/usr/libexec|${PREFIX}/libexec|g'			\
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|'		\
		-e 's|${LOCALBASE}/man|${MANPREFIX}/man|'		\
		${BUILD_WRKSRC}/${pyscr}
.endfor
.for pyscr in miro.real timetemplates.py
	${REINPLACE_CMD} -e 's|python2.4|${PYTHON_VERSION}|'		\
		-e '/^PREFIX/s|/usr|${PREFIX}|' ${BUILD_WRKSRC}/${pyscr}
.endfor
	${REINPLACE_CMD} -e 's|BOOST_LIB_PATH|${LOCALBASE}/lib|'	\
		${WRKSRC}/portable/setup_portable.py
	${REINPLACE_CMD} -e 's|return "Linux"|return "${OPSYS}"|'	\
		${BUILD_WRKSRC}/platform/__init__.py

do-build:
	(cd ${BUILD_WRKSRC} &&	\
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py build)

do-install:
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV}		\
	${PYTHON_CMD} setup.py install --prefix=${PREFIX})
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py	\
	${PYTHON_SITELIBDIR}/miro

.if defined(MAINTAINER_MODE)
regression-test:	install
	LANG=C LC_ALL=C ${PREFIX}/bin/miro --unittest
.endif

.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>

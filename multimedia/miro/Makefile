# New ports collection makefile for:	Democracy
# Date created:		30 November 2006
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	Miro
PORTVERSION=	2.0.4
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.osuosl.org/pub/pculture.org/miro/src/	\
		http://ftp.osuosl.org/pub/pculture.org/miro/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A video player to get internet TV broadcasts

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex				\
		update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python		\
		xine.1:${PORTSDIR}/multimedia/libxine
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb	\
		${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite23	\
		${PYTHON_SITELIBDIR}/dbus/glib.py:${PORTSDIR}/devel/py-dbus	\
		convert:${PORTSDIR}/graphics/ImageMagick

BUILD_WRKSRC=	${WRKSRC}/platform/gtk-x11
INSTALL_WRKSRC=	${WRKSRC}/platform/gtk-x11

USE_GCC=	4.3+
USE_GNOME=	gtk20 pygnomeextras
USE_GECKO=	firefox libxul seamonkey xulrunner mozilla
USE_OPENSSL=	yes
USE_PYTHON=	yes
WANT_GSTREAMER=	yes
USE_GETTEXT=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME:L}
MAKE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
INSTALLS_EGGINFO=	yes

MANCOMPRESSED=	yes
MAN1=		miro.1 miro.real.1

DATADIR=	${PREFIX}/share/${PORTNAME:L}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

.if defined(WITH_GSTREAMER)
USE_GSTREAMER+=	python
.endif

.if defined(GECKO) && ${GECKO:Mlibxul}!=""
XPCOM_LIB=	${GECKO}
GTKMOZEMBED_LIB=${GECKO}
XULRUNNER_19=	True
.else
XPCOM_LIB=	${GECKO}-xpcom
GTKMOZEMBED_LIB=${GECKO}-gtkmozembed
XULRUNNER_19=	False
.endif

.SILENT:

post-patch:
.for file in setup.py plat/resources.py
	${REINPLACE_CMD} -e 's|%%XPCOM_LIB%%|${XPCOM_LIB}|g ; \
		 s|%%GTKMOZEMBED_LIB%%|${GTKMOZEMBED_LIB}|g ; \
		 s|%%XULRUNNER_19%%|${XULRUNNER_19}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%CC%%|${CC}|g ; \
		 s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%MANPREFIX%%|${MANPREFIX}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in miro.real
	${REINPLACE_CMD} -e 's|python2.4|${PYTHON_VERSION}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in run.sh
	${REINPLACE_CMD} -e 's|^PREFIX=.*|PREFIX=${PREFIX}|g' \
		${BUILD_WRKSRC}/${file}
.endfor
.for file in plat/renderers/xinerenderer.py
	${REINPLACE_CMD} -e 's|lib/miro|libexec/miro|g' \
		${BUILD_WRKSRC}/${file}
.endfor

.if defined(MAINTAINER_MODE)
regression-test:	install
	LANG=C LC_ALL=C ${PREFIX}/bin/miro --unittest
.endif

.include <bsd.port.post.mk>

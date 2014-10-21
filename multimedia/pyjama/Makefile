# Created by: Kjell Tore Ullavik <ktullavik@gmail.com>
# $FreeBSD$

PORTNAME=	pyjama
PORTVERSION=	0.3.0.1
PORTREVISION=	6
CATEGORIES=	multimedia python
MASTER_SITES=	http://launchpadlibrarian.net/26637583/
DISTNAME=	pyjama-0.3.0.1_all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Frontend to the Jamendo music network

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson	\
		${PYTHON_PKGNAMEPREFIX}gstreamer>=0.10:${PORTSDIR}/multimedia/py-gstreamer

NO_BUILD=	yes
USE_GSTREAMER=	core good bad gnomevfs
USE_GNOME=	pygtk2
USES=		gettext python

LOCALES=	bg ca da de en_GB es fr it pl
INSTDIR=	${PYTHON_SITELIBDIR}/${PORTNAME}
INSTSUBDIRS=	clLayouts extended_modules images modules plugins themes
INSTFILES=	about.glade preferences.glade pyjama.cfg pyjama_test.glade \
		pyjama.doxygen.py pyjama.py pyjama_test.glade

post-patch:
	${REINPLACE_CMD} -i '' 's|path = "locale"|path = "${PREFIX}/share/locale"|' \
		${WRKSRC}/src/modules/functions.py
	${REINPLACE_CMD} -i '' 's|INSTALL_DIR_POSIX = "/usr/share/apps/pyjama"|INSTALL_DIR_POSIX = "${INSTDIR}"|' \
		${WRKSRC}/src/modules/constants.py
	${FIND} ${WRKSRC} -name "*~" -delete

do-install:
	${MKDIR} ${STAGEDIR}${INSTDIR}

.for f in ${INSTFILES}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${STAGEDIR}${INSTDIR}
.endfor

.for dir in ${INSTSUBDIRS}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${INSTDIR}
.endfor

.for loc in ${LOCALES}
	${INSTALL_DATA} ${WRKSRC}/src/locale/${loc}/LC_MESSAGES/pyjama.mo ${STAGEDIR}${PREFIX}/share/locale/${loc}/LC_MESSAGES/
.endfor

	${LN} -fs ${INSTDIR}/pyjama.py ${STAGEDIR}${PREFIX}/bin/pyjama
	${CHMOD} a+x ${STAGEDIR}${INSTDIR}/pyjama.py
	${INSTALL_DATA} ${WRKSRC}/src/pyjama.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/images/pyjama.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>

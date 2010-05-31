# New ports collection makefile for:	pyjama
# Date created:				10. Sep 2009
# Whom:					Kjell Tore Ullavik <ktullavik@gmail.com>
#
# $FreeBSD$

PORTNAME=	pyjama
PORTVERSION=	0.3.0.1
PORTREVISION=	4
CATEGORIES=	multimedia python
MASTER_SITES=	http://launchpadlibrarian.net/26637583/
DISTNAME=	pyjama-0.3.0.1_all

MAINTAINER=	ktullavik@gmail.com
COMMENT=	Frontend to the Jamendo music network

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysqlite>=2.3:${PORTSDIR}/databases/py-pysqlite23 \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson	\
		${PYTHON_PKGNAMEPREFIX}gstreamer>=0.10:${PORTSDIR}/multimedia/py-gstreamer

NO_BUILD=	yes

USE_PYTHON=	2.4+
USE_GSTREAMER=	core good bad
USE_GNOME=	pygtk2
USE_GETTEXT=	yes

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
	${MKDIR} ${INSTDIR}

.	for f in ${INSTFILES}
	    ${INSTALL_DATA} ${WRKSRC}/src/${f} ${INSTDIR}
.	endfor

.	for dir in ${INSTSUBDIRS}
		cd ${WRKSRC}/src && ${COPYTREE_SHARE} ${dir} ${INSTDIR}
.	endfor

.	for loc in ${LOCALES}
		${INSTALL_DATA} ${WRKSRC}/src/locale/${loc}/LC_MESSAGES/pyjama.mo ${PREFIX}/share/locale/${loc}/LC_MESSAGES/
.	endfor

	${LN} -fs ${INSTDIR}/pyjama.py ${PREFIX}/bin/pyjama
	${CHMOD} a+x ${INSTDIR}/pyjama.py
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/pyjama.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/src/images/pyjama.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>

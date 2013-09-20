# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	turpial
PORTVERSION=	1.6.7.1
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	http://turpial.org.ve/files/sources/%SUBDIR%/
MASTER_SITE_SUBDIR=	stable
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1/-1/}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Twitter and Identi.ca client written in Python

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0.9:${PORTSDIR}/devel/py-babel
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/notify-python.pc:${PORTSDIR}/devel/py-notify \
		${LOCALBASE}/libdata/pkgconfig/pywebkitgtk-1.0.pc:${PORTSDIR}/www/py-webkitgtk \
		${PYTHON_SITELIBDIR}/setproctitle.so:${PORTSDIR}/devel/py-setproctitle \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

USE_PYTHON=	yes
USE_GNOME=	pygobject pygtk2 desktopfileutils
USE_GSTREAMER=	python

REINPLACE_ARGS=	-i ""

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
DATADIR=	${PREFIX}/share/${PORTNAME}

LOCALES_DIR=	ca ca_ES cs de en es es_ES es_VE eu fr gl he hu it nl nn \
	pt pt_BR ru ru_RU sr uk_UA zh_CN zh_TW

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Since Python > 2.7, optparse module is deprecated
.if ${PYTHON_REL} >= 270
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-argparse-turpial_main.py
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-optparse-turpial_main.py
.endif

post-patch:
	@${FIND} ${WRKSRC}/turpial -type f -regex '.*\.py' \
		| ${XARGS} ${REINPLACE_CMD} 's|bin/python|bin/env python| ; \
		s|Linux|FreeBSD|g ; \
		s|from turpial\.|from |g ; \
		s|%%PREFIX%%|${PREFIX}|g'

do-build:
	@cd ${WRKSRC} && \
		${PYTHON_CMD} setup.py compile_catalog --directory turpial/i18n ; \
		${PYTHON_CMD} -m compileall ${WRKSRC} ; \
		${PYTHON_CMD} -O -m compileall ${WRKSRC}

	@${ECHO_CMD} "#!/bin/sh" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "cd ${DATADIR} || exit 1" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "exec ${PYTHON_CMD} main.py" >> ${WRKDIR}/run.sh

pre-install:
	@${FIND} ${WRKSRC} -type f -name '*.orig' \
		-exec ${RM} -f "{}" \;

	@${MKDIR} -p ${DOCSDIR} ${DATADIR} \
		${PREFIX}/share/pixmaps \
		${PREFIX}/share/applications \
		${PREFIX}/bin
.for LOCALE in ${LOCALES_DIR}
	@${MKDIR} -p ${PREFIX}/share/locale/${LOCALE}/LC_MESSAGES
.endfor
	@cd ${WRKSRC}/turpial && \
		${FIND} . -type d \
			\! -regex '.*i18n.*' -exec ${MKDIR} -p "${DATADIR}/{}" \;

do-install:
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS COPYING TRANSLATORS README.rst ${DOCSDIR} ; \
		${INSTALL_DATA} turpial/data/pixmaps/turpial.png \
			${PREFIX}/share/pixmaps ; \
		${INSTALL_DATA} ${PORTNAME}.desktop ${PREFIX}/share/applications

	@cd ${WRKSRC}/turpial/i18n && \
		${FIND} . -type f -name '*.mo' \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/share/locale/{}" \;

	@cd ${WRKSRC}/turpial && \
		${FIND} . -type f \
			\( ! -name '*.mo' -and ! -name '*.po*' \) \
			-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

	${INSTALL_SCRIPT} ${WRKDIR}/run.sh ${PREFIX}/bin/${PORTNAME}

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>

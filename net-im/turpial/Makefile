# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	turpial
PORTVERSION=	1.6.9
CATEGORIES=	net-im python
MASTER_SITES=	http://files.turpial.org.ve/sources/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Twitter and Identi.ca client written in Python

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:${PORTSDIR}/devel/py-babel
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notify>=0.1.1:${PORTSDIR}/devel/py-notify \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>=1.1.8:${PORTSDIR}/www/py-webkitgtk \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.7:${PORTSDIR}/devel/py-setproctitle \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.19:${PORTSDIR}/devel/py-xdg

USE_PYTHON=	2
USE_GNOME=	pygobject pygtk2
USE_GSTREAMER=	python

REINPLACE_ARGS=	-i ""

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
DATADIR=	${PREFIX}/share/${PORTNAME}

LOCALES_DIR=	ca ca_ES cs de en es es_ES es_VE eu fr gl he hu it nl nn \
	pt pt_BR ru ru_RU sr uk_UA zh_CN zh_TW

.include <bsd.port.pre.mk>

# Since Python > 2.7, optparse module is deprecated
.if ${PYTHON_REL} >= 270
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-argparse-turpial_main.py
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-optparse-turpial_main.py
.endif

post-patch:
	@${FIND} ${WRKSRC}/turpial -type f -name '*.py' \
		| ${XARGS} ${REINPLACE_CMD} 's|bin/python|bin/env python| ; \
		s|Linux|FreeBSD|g ; \
		s|from turpial\.|from |g ; \
		s|%%PREFIX%%|${PREFIX}|g'

do-build:
	@cd ${WRKSRC} && \
		${PYTHON_CMD} setup.py compile_catalog --directory turpial/i18n
	@${PYTHON_CMD} -m compileall ${WRKSRC}

	@${ECHO_CMD} "#!/bin/sh" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "cd ${DATADIR} || exit 1" >> ${WRKDIR}/run.sh
	@${ECHO_CMD} "exec ${PYTHON_CMD} main.py" >> ${WRKDIR}/run.sh

pre-install:
	@${FIND} ${WRKSRC} -type f -name '*.orig' \
		| ${XARGS} rm

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKDIR}/run.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for dir in ${LOCALES_DIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${dir}/LC_MESSAGES
	@cd ${WRKSRC}/turpial/i18n && \
		${INSTALL_DATA} ${dir}/LC_MESSAGES/${PORTNAME}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${dir}/LC_MESSAGES
.endfor

.for dir in ${PORTNAME} pixmaps applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${dir}
.endfor
	@cd ${WRKSRC} && \
		${INSTALL_DATA} turpial/data/pixmaps/turpial.png \
			${STAGEDIR}${PREFIX}/share/pixmaps ; \
		${INSTALL_DATA} ${PORTNAME}.desktop \
			${STAGEDIR}${PREFIX}/share/applications
	@${RM} -R ${WRKSRC}/turpial/i18n
	@cd ${WRKSRC}/turpial && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && \
		${INSTALL_DATA} AUTHORS COPYING TRANSLATORS README.rst \
			${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>

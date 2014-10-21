# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	photofilmstrip
PORTVERSION=	1.5.0
PORTREVISION=	7
CATEGORIES=	multimedia python
MASTER_SITES=	SF/photostoryx/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Creates movies out of your pictures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer

PORTSCOUT=	skipv:1.9.90,1.9.91	# Unstable Versions

USES=		python
USE_WX=		3.0+
WX_COMPS=	python:lib
ALL_TARGET=	compile

PFSDIR=		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

pre-everything::
	@${ECHO_MSG} "To run ${PORTNAME}, you must have sqlite3 installed with extensions enabled."

post-patch:
	@${REINPLACE_CMD} -e \
		's|make -C|$$(MAKE) -C|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		'/^prefix/s|=.*|= ${PREFIX}|g ; \
		 /^appdir/s|=.*|= ${PFSDIR}|g' ${WRKSRC}/Makefile.rules
	@${REINPLACE_CMD} -e \
		'/^prefix/d ; \
		 /^export/s|=.*|=${PFSDIR}|g ; \
		 s|/usr/bin/python|${PYTHON_CMD}|g' ${WRKSRC}/build/${PORTNAME}
	@${REINPLACE_CMD} -e \
		'/^prefix/d ; \
		 /^export/s|=.*|=${PFSDIR}|g ; \
		 s|/usr/bin/python|${PYTHON_CMD}|g' ${WRKSRC}/build/${PORTNAME}-cli
	@${REINPLACE_CMD} -e \
		'/^Version/s|=.*|=${PORTVERION}|g ; \
		 s|/usr/share/pixmaps/||g ; \
		 /^Categories/s|=.*|=Application;AudioVideo;AudioVideoEditing|g ; \
		 /^OnlyShowIn/d' ${WRKSRC}/build/${PORTNAME}.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/${PORTNAME}-cli ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PFSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}-cli.py ${STAGEDIR}${PFSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}-gui.py ${STAGEDIR}${PFSDIR}
.for dir in cli core gui lib res
	@(cd ${WRKSRC}/src && \
		${FIND} ${dir} ! \( -name '*.bak' -o -name '*.orig' \) | \
		${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${PFSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${PFSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/photofilmstrip/* ${STAGEDIR}${PFSDIR}/doc
	@${FIND} ${STAGEDIR}${PFSDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${STAGEDIR}${PFSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
.for lang in cs de en fr it ko nl pt tr
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/PhotoFilmStrip.mo
.endfor
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>

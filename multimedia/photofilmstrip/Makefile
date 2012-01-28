# ex:ts=8
# Ports collection makefile for:	photofilmstrip
# Date created:		2011-02-04
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	photofilmstrip
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/photostoryx/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates movies out of your pictures

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer

USE_PYTHON=	yes
USE_WX=		2.8+
WX_COMPS=	python:lib
WX_UNICODE=	yes
USE_GETTEXT=	yes
ALL_TARGET=	compile

PFSDIR=		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

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
	${INSTALL_SCRIPT} ${WRKSRC}/build/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/${PORTNAME}-cli ${PREFIX}/bin
	@${MKDIR} ${PFSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}-cli.py ${PFSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}-gui.py ${PFSDIR}
.for dir in cli core gui lib res
	@(cd ${WRKSRC}/src && \
		${FIND} ${dir} ! \( -name '*.bak' -o -name '*.orig' \) | \
		${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${PFSDIR})
.endfor
	@${MKDIR} ${PFSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/doc/photofilmstrip/* ${PFSDIR}/doc
	@${FIND} ${PFSDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${PFSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.desktop ${PREFIX}/share/applications
.for lang in cs de en fr it ko nl pt tr
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/PhotoFilmStrip.mo
.endfor
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>

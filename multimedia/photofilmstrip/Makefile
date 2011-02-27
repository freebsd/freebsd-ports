# ex:ts=8
# Ports collection makefile for:	photofilmstrip
# Date created:		2011-02-04
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	photofilmstrip
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	SF/photostoryx/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	corky1951@comcast.net
COMMENT=	PhotoFilmStrip creates movies out of your pictures

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	yes
USE_WX=		2.8+
WX_COMPS=	python:lib
WX_UNICODE=	yes
USE_GETTEXT=	yes

LICENSE=	GPLv2

pre-everything::
	@${ECHO_MSG} "To run ${PORTNAME}, you must have sqlite3 installed with extensions enabled."

ALL_TARGET=	compile

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/Makefile.rules
	@${REINPLACE_CMD} -e 's|^appdir.*|appdir = ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}|' ${WRKSRC}/Makefile.rules
	@${REINPLACE_CMD} -e 's|prefix=.*||' \
		-e 's|export.*|export PFSDIR=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}|' \
		-e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/build/${PORTNAME}
	@${REINPLACE_CMD} -e 's|prefix=.*||' \
		-e 's|export.*|export PFSDIR=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}|' \
		-e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/build/${PORTNAME}-cli
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/build/${PORTNAME}.desktop

.include <bsd.port.mk>

# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	rpcalc
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Simple RPN calculator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:x11-toolkits/py-qt4-gui

USES=		python:3.3+

NO_BUILD=	yes
INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="rpCalc" \
		"" \
		"${PREFIX}/share/icons/${PORTNAME}/calc_lg.png" \
		"${PORTNAME}" \
		"Qt;Utility;Calculator;" \
		"false"

PLIST_SUB=	PYTHON_SUFFIX="${PYTHON_SUFFIX}"
WRKSRC=		${WRKDIR}/rpCalc

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py -p ${PREFIX} -b ${STAGEDIR})
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${DATADIR} -f ${DATADIR_REL})
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${DATADIR} -f ${DATADIR_REL})

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE= you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>

# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	convertall
PORTVERSION=	0.6.1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Another unit converter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

USES=		pyqt:4 python:3.3+
USE_PYQT=	core gui

CONFIGURE_ARGS=	-p ${PREFIX} -d ${DOCSDIR} -i ${DATADIR}/icons -b ${STAGEDIR}
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ConvertAll

DESKTOP_ENTRIES="ConvertAll" \
		"Unit Converter" \
		"${DATADIR}/icons/${PORTNAME}.svg" \
		"${PORTNAME}" \
		"Qt;Utility;Calculator;" \
		false

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	-s

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py ${CONFIGURE_ARGS})
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${DATADIR} -f ${DATADIR_REL})
	(cd ${STAGEDIR}${DOCSDIR} && ${RM} INSTALL LICENSE)

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
PYOEXTENSION=	pyo
.else
PYOEXTENSION=	opt-1.pyc
.endif

PLIST_SUB+=	PYTHON_SUFFIX="${PYTHON_SUFFIX}" \
		PYOEXTENSION="${PYOEXTENSION}"

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>

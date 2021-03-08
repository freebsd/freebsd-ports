# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	convertall
PORTVERSION=	0.8.0
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	https://github.com/doug-101/ConvertAll/releases/download/v${PORTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Another unit converter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

USES=		pyqt:5 python:3.5+ shebangfix
USE_PYQT=	core gui widgets sip

SHEBANG_FILES=	source/convertall.py

CONFIGURE_ARGS=	-p ${PREFIX} -d ${DOCSDIR} -i ${DATADIR}/icons -b ${STAGEDIR}
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ConvertAll

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	-s

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py ${CONFIGURE_ARGS})
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${DATADIR} -f ${DATADIR_REL})
	(cd ${STAGEDIR}${DOCSDIR} && ${RM} INSTALL LICENSE)

.include <bsd.port.mk>

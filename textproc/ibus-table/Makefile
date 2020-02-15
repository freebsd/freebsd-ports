# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	ibus-table
DISTVERSION=	1.9.25
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Table-based input method framework for IBus

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		docbook2man:textproc/docbook-utils \
		docbook-sgml>0:textproc/docbook-sgml
LIB_DEPENDS=	libibus-1.0.so:textproc/ibus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		autoreconf gmake pkgconfig python:3.4+
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	kaio

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/|${PREFIX}/|g" ${WRKSRC}/engine/*.py

post-install:
	@${RM} -r ${STAGEDIR}${DATADIR}/*/__pycache__

.include <bsd.port.mk>

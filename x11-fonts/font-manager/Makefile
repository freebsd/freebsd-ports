# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	font-manager
PORTVERSION=	0.5.7
PORTREVISION=	5
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	lichray@gmail.com
COMMENT=	Font management application for the GNOME desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig python:2 tar:bzip2

PORTDATA=	*

OPTIONS_DEFINE=	REPORTLAB NLS
REPORTLAB_DESC=	Enable font-sampler (PDF sample sheet)

OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

REPORTLAB_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/:print/py-reportlab2

.include <bsd.port.mk>

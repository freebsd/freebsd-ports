# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	font-manager
PORTVERSION=	0.5.7
PORTREVISION=	4
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	lichray@gmail.com
COMMENT=	Font management application for the GNOME desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_BZIP2=	yes
USE_PYTHON=	2
USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

PORTDATA=	*

OPTIONS_DEFINE=	REPORTLAB NLS
REPORTLAB_DESC=	Enable font-sampler (PDF sample sheet)

OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

REPORTLAB_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/reportlab/:${PORTSDIR}/print/py-reportlab2

.include <bsd.port.mk>

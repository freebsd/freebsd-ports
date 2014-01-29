# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	font-manager
PORTVERSION=	0.5.7
PORTREVISION=	3
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	lichray@gmail.com
COMMENT=	A font management application for the GNOME desktop

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_BZIP2=	yes
USE_PYTHON=	2
USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

LICENSE_FILE=	${WRKSRC}/COPYING
PORTDATA=	*

OPTIONS_DEFINE=	REPORTLAB NLS
REPORTLAB_DESC=	Enable font-sampler (PDF sample sheet)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if defined(NOPORTDATA)
IGNORE=	port data is source code, undefine NOPORTDATA
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MREPORTLAB}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/:${PORTSDIR}/print/py-reportlab2
.endif

.include <bsd.port.mk>

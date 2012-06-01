# New ports collection makefile for:	font-manager
# Date created:		2011-03-25
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	font-manager
PORTVERSION=	0.5.7
PORTREVISION=	3
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	lichray@gmail.com
COMMENT=	A font management application for the GNOME desktop

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_BZIP2=	yes
USE_PYTHON=	2.6-2.7
USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

LICENSE_FILE=	${WRKSRC}/COPYING
PORTDATA=	*

OPTIONS=	REPORTLAB "Enable font-sampler (PDF sample sheet)" off \
		NLS "Enable Native Language Support" on

.include <bsd.port.options.mk>

.if defined(NOPORTDATA)
IGNORE=	port data is source code, undefine NOPORTDATA
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_REPORTLAB)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/reportlab/:${PORTSDIR}/print/py-reportlab2
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	ibus-table
# Date created:		20 November 2009
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	ibus-table
PORTVERSION=	1.2.0.20091113
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Table based input method framework for IBus

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
LIB_DEPENDS=	ibus.1:${PORTSDIR}/textproc/ibus
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_GNOME=	pkgconfig pygtk2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PROJECTHOST=	ibus

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|/usr/|${PREFIX}/|g" ${WRKSRC}/engine/*.py

.include <bsd.port.mk>

# New ports collection makefile for:	gajim-devel
# Date created:				Sun Nov 26 16:36:07 MSK 2006
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	20090608
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://wizard.volgograd.ru/distfiles/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-2009-06-08

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Gajim is a Jabber client based on a plugin system

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	2.4+
USE_XORG=	x11 xext xscrnsaver

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" PYTHON=${PYTHON_CMD}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-0.12.1.5-svn

MAN1=		gajim.1

ACTIVITIES=	default
EMOTICONS=	animated static static-big
ICONSETS=	crystal dcraven gnome goojim gossip gota jabberbulb nuvola \
		simplebulb stellar sun transports
MOODS=		default

pre-build:
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/src

post-install:
		${MKDIR} ${DATADIR}/data/activities
		(cd ${WRKSRC}/data/activities && \
		${COPYTREE_SHARE} "${ACTIVITIES}" ${DATADIR}/data/activities)

		${MKDIR} ${DATADIR}/data/emoticons
		(cd ${WRKSRC}/data/emoticons && \
		${COPYTREE_SHARE} "${EMOTICONS}" ${DATADIR}/data/emoticons)

		${MKDIR} ${DATADIR}/data/iconsets
		(cd ${WRKSRC}/data/iconsets && \
		${COPYTREE_SHARE} "${ICONSETS}" ${DATADIR}/data/iconsets)

		${MKDIR} ${DATADIR}/data/moods
		(cd ${WRKSRC}/data/moods && \
		${COPYTREE_SHARE} "${MOODS}" ${DATADIR}/data/moods)

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.else
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite23
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://snapshot.opera.com/unix/${OPERA_VER}-${OPERA_REL}/intel-freebsd/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_DATE}.${OPERA_TYPE}-${OPERA_LIB}-qt.i386.freebsd-en

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

OPERA_VER=	9.0
OPERA_REL=	Preview-2
OPERA_DATE=	20060206

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_X_PREFIX=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

OPTIONS=	SHARED	"Use a shared Qt library (instead of static)"	${QT_PRESENT} \
		ASPELL	"Use the aspell library for spell checking"	on

.if exists(${X11BASE}/lib/libqt-mt.prl)
QT_PRESENT=	on
.else
QT_PRESENT=	off
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
OPERA_TYPE=	4
.elif ${OSVERSION} >= 500000
OPERA_TYPE=	3
.else
OPERA_TYPE=	2
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.endif

.if defined(WITH_SHARED)
OPERA_LIB=	shared
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
.else
OPERA_LIB=	static
OPERA_TYPE=	1
.endif

.if ${OPERA_TYPE} == 1 && ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	z.2:${PORTSDIR}/misc/compat5x
.endif
.endif

.if ${HAVE_GNOME:Mgnomehier}!=""
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

.if exists(${LOCALBASE}/bin/kde-config)
PLIST_SUB+=	KDE=""
.else
PLIST_SUB+=	KDE="@comment "
.endif

post-patch:
	@${CP} ${WRKSRC}/search.ini ${WRKSRC}/locale/en
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%X11BASE%%|${X11BASE}|g' \
			${WRKSRC}/install.sh ${WRKSRC}/ini/pluginpath.ini \
			${WRKSRC}/ini/spellcheck.ini ${WRKSRC}/config/opera6rc
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install.sh --prefix=${PREFIX})

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

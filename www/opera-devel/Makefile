# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
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
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

.ifndef(WITHOUT_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
OPERA_TYPE=	4
WITH_SHARED=	yes
.elif ${OSVERSION} >= 500000
OPERA_TYPE=	3
WITH_SHARED=	yes
.elifdef WITH_SHARED
OPERA_TYPE=	2
.else
OPERA_TYPE=	1
.endif

.if defined(WITH_SHARED)
OPERA_LIB=	shared
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
.else
OPERA_LIB=	static
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

pre-everything::
.if !defined(WITHOUT_ASPELL) || !defined(WITH_SHARED)
	@${ECHO_CMD} '===> The following options are available for this port:'
	@${ECHO_CMD} '===>'
.if !defined(WITHOUT_ASPELL)
	@${ECHO_CMD} '===> Define WITHOUT_ASPELL to not install aspell.'
.endif
.if !defined(WITH_SHARED)
	@${ECHO_CMD} '===> Define WITH_SHARED to use a shared Qt library.'
.endif
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

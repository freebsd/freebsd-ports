# New ports collection makefile for:		linux-opera
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	${OPERA_VER}.${OPERA_DATE}
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.opera.com/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		ftp://ftp.sunet.se/pub/www/clients/Opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		ftp://sunsite.cnlab-switch.ch/mirror/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		ftp://ftp.tiscali.nl/pub/mirrors/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		ftp://ftp.ntua.gr/pub/www/Opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		http://mirrors.pmmf.hu/mirror/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		ftp://ftp.task.gda.pl/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		ftp://ftp.planetmirror.com/pub/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		http://gd.tuwien.ac.at/infosys/browsers/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/opera/linux/${OPERA_VER:S/.//}/final/en/i386/static/&,}
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${OPERA_VER}-${OPERA_DATE}.1-static-qt.i386-en

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

RUN_DEPENDS=	\
		${LINUXBASE}/usr/lib/libaspell.so.15:${PORTSDIR}/textproc/linux-aspell \
		${LINUXBASE}/usr/X11R6/lib/libXm.so.3.0.3:${PORTSDIR}/x11-toolkits/linux-openmotif

RESTRICTED=	"not redistributable; commercial software"

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_LINUX=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes

OPERA_VER=	8.02
OPERA_DATE=	20050727
DATADIR=	${PREFIX}/share/${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier}!=""
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

.if exists(${LOCALBASE}/bin/kde-config)
PLIST_SUB+=	KDE:=""
.else
PLIST_SUB+=	KDE:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%X11BASE%%|${X11BASE}|g' \
			${WRKSRC}/install.sh ${WRKSRC}/ini/pluginpath.ini \
			${WRKSRC}/ini/spellcheck.ini ${WRKSRC}/config/opera6rc
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@(cd ${WRKSRC} && ./install.sh \
			--prefix=${PREFIX} \
			--docdir=${DOCSDIR} \
			--sharedir=${DATADIR} \
			--exec_prefix=${DATADIR}/bin \
			--plugindir=${DATADIR}/plugins)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

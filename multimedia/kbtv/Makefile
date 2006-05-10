# New ports collection makefile for:	kbtv
# Date created:				Tue Oct  4 01:59:31 UTC 2005
# Whom:					danny@ricin.com
#
# $FreeBSD$
#

PORTNAME=	kbtv
DISTVERSION=	1.0-rc2
CATEGORIES=	multimedia python kde
MASTER_SITES=	http://freebsd.ricin.com/ports/distfiles/
EXTRACT_SUFX=	.tbz

MAINTAINER=	danny@ricin.com
COMMENT=	Simple KDE TV viewer for BSD

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt \
		kdepyuic:${PORTSDIR}/x11-toolkits/py-kde \
		mplayer:${PORTSDIR}/multimedia/mplayer
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	YES
USE_KDELIBS_VER=3
USE_PYTHON=	yes

OPTIONS=	DOCS "Install (KDE) documentation" on \
		MANPAGES "Install btcontrol manpage" on \
		MAN_COMPRESS "Compress manpage" on \
		UIFILES "Install Designer (ui) files" on

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
PLIST_SUB+=	DOCS="@comment "
.else
PLIST_SUB+=	DOCS=""
.endif

.if defined(NO_INSTALL_MANPAGES) || defined(WITHOUT_MANPAGES)
PLIST_SUB+=	MAN="@comment "
.else
PLIST_SUB+=	MAN=""
.endif

.if defined(NOMANCOMPRESS) || defined(WITHOUT_MAN_COMPRESS)
PLIST_SUB+=	CMAN="man1/btcontrol.1"
.else
PLIST_SUB+=	CMAN="man1/btcontrol.1.gz"
.endif

.if defined(WITHOUT_UIFILES)
PLIST_SUB+=	UI="@comment "
.else
PLIST_SUB+=	UI=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX = /usr/local|PREFIX = ${PREFIX}|' \
		${WRKSRC}/install.cfg
.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
	@${REINPLACE_CMD} -e 's|INSTALL_DOCS = yes|INSTALL_DOCS = |' \
		${WRKSRC}/install.cfg
.endif
.if defined(NOMANCOMPRESS) || defined(WITHOUT_MAN_COMPRESS)
	@${REINPLACE_CMD} -e 's|MANPAGES_COMPRESS = yes|MANPAGES_COMPRESS = |' \
		${WRKSRC}/install.cfg
.endif
.if defined(NO_INSTALL_MANPAGES) || defined(WITHOUT_MANPAGES)
	@${REINPLACE_CMD} -e 's|INSTALL_MANPAGES = yes|INSTALL_MANPAGES = |' \
		${WRKSRC}/install.cfg
.endif
.if defined(WITHOUT_UIFILES)
	@${REINPLACE_CMD} -e 's|INSTALL_UIFILES = yes|INSTALL_UIFILES = |' \
		${WRKSRC}/install.cfg
.endif

do-configure:
	@(cd ${WRKSRC} && ${MAKE} configure)

.include <bsd.port.post.mk>

# New ports collection makefile for:	moztraybiff
# Date created:				19 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moztraybiff
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://mozdev.oregonstate.edu/moztraybiff/
DISTNAME=	mozTrayBiff-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	New mail tray icon for Thunderbird

BUILD_DEPENDS=	${X11BASE}/lib/thunderbird/lib/thunderbird-${TBVER}/components/libwidget_gtk2.so:${PORTSDIR}/mail/thunderbird \
		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	${X11BASE}/lib/thunderbird/lib/thunderbird-${TBVER}/components/libwidget_gtk2.so:${PORTSDIR}/mail/thunderbird

TBVER!=		cd ../thunderbird && ${MAKE} -V PORTVERSION

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnome
USE_REINPLACE=	yes
MAKE_ARGS+=	MOZILLA_PLATFORM=tbird

FILENAME=	mozTrayBiff-${PORTVERSION}-FreeBSD-tb${TBVER}.xpi
PLIST_FILES=	${DATADIR}/${FILENAME}
PLIST_DIRS=	${DATADIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e "s|-fshort-wchar||" \
		${WRKSRC}/components/Makefile
.endif
	@${REINPLACE_CMD} -e "s|%%TBVER%%|${TBVER}|" \
		${WRKSRC}/components/Makefile

post-build:
	${SED} 's|%%DATADIR%%|${DATADIR}|' ${PKGDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL} -m 644 ${WRKSRC}/${FILENAME} ${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

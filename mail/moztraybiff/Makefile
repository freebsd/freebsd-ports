# New ports collection makefile for:	moztraybiff
# Date created:				19 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moztraybiff
PORTVERSION=	1.2.1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	mozTrayBiff-${PORTVERSION}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	New mail tray icon for Thunderbird

BUILD_DEPENDS=	${X11BASE}/lib/thunderbird/components/libwidget_gtk2.so:${PORTSDIR}/mail/thunderbird \
		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	${X11BASE}/lib/thunderbird/components/libwidget_gtk2.so:${PORTSDIR}/mail/thunderbird

.if !exists(../thunderbird/Makefile)
BROKEN=		${PORTNAME} needs the Thunderbird port in order to build
.else
TBVER!=		cd ../thunderbird && ${MAKE} -V PORTVERSION
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnome
USE_REINPLACE=	yes
MAKE_ARGS+=	MOZILLA_PLATFORM=tbird TBVER=${TBVER}

FILENAME=	mozTrayBiff-${PORTVERSION}-tb${TBVER}.xpi
PLIST_FILES=	share/${PORTNAME}/${FILENAME}
PLIST_DIRS=	share/${PORTNAME}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e "s|-fshort-wchar||" \
		${WRKSRC}/components/Makefile
.endif
	@${REINPLACE_CMD} -e "s|^#!/bin/bash|#!/bin/sh|" \
		${WRKSRC}/get-platform

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL} -m 644 ${WRKSRC}/${FILENAME} ${DATADIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>

# New ports collection makefile for:	moztraybiff
# Date created:				19 March, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moztraybiff
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_MOZDEV}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	mozTrayBiff-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	New mail tray icon for Thunderbird

BUILD_DEPENDS=	${LOCALBASE}/lib/thunderbird/components/libwidget_gtk2.so:${PORTSDIR}/mail/thunderbird \
		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	${LOCALBASE}/lib/thunderbird/components/libwidget_gtk2.so:${PORTSDIR}/mail/thunderbird

USE_GMAKE=	yes
USE_GNOME=	libgnome

.include <bsd.port.pre.mk>

.if !exists(${PORTSDIR}/mail/thunderbird/Makefile)
BROKEN=		${PORTNAME} needs the Thunderbird port in order to build
.else
TBVER!=		(cd ${PORTSDIR}/mail/thunderbird && ${MAKE} -V PORTVERSION)
.endif

MAKE_ARGS+=	MOZILLA_PLATFORM=tbird TBVER=${TBVER} MOZ_TRUNK=0

FILENAME=	mozTrayBiff-${PORTVERSION}-tb${TBVER}.xpi
PLIST_FILES=	share/${PORTNAME}/${FILENAME}
PLIST_DIRS=	share/${PORTNAME}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
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

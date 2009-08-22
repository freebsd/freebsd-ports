# New ports collection makefile for:  	bbmail
# Date created:		May 3 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bbmail
PORTVERSION=	0.9.3
CATEGORIES=	mail
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool intended for Blackbox that checks for new mail

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libbt.pc:${PORTSDIR}/x11-wm/blackbox

USE_XORG=	xext
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

MAN1=		bbmail.1
PLIST_FILES=	bin/bbmail share/bbtools/bbmail.rc

post-install:
	@${ECHO_CMD} "@unexec rmdir %D/share/bbtools 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>

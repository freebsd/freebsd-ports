# New ports collection makefile for:	guiTAR
# Date created:			Sat Aug 14 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	guiTAR
PORTVERSION=	0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://disq.bir.net.tr/guitar/ \
		http://artemis.efes.net/disq/guitar/

MAINTAINER=	domi@saargate.de

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS+=--disable-gnome
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/guitar ${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPTDIR}/bsdtar2gnutar ${PREFIX}/bin

.include <bsd.port.post.mk>

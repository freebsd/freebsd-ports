# New ports collection makefile for:	xruskb
# Date created:		14 Jan 1998
# Whom:			Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	xruskb
PORTVERSION=	1.15.3
PORTREVISION=	1
CATEGORIES=	russian x11
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/X11/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A keyboard layout switcher and indicator

USE_X_PREFIX=	YES
USE_BZIP2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=${PREFIX}/share
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if defined(WITH_MOTIF)
CONFIGURE_ARGS+=	--with-toolkit=motif
LIB_DEPENDS=		Xm.3:${PORTSDIR}/x11-toolkits/open-motif
.else
CONFIGURE_ARGS+=	--with-toolkit=none

pre-configure:
	@${ECHO_MSG} "*"
	@${ECHO_MSG} "* Use WITH_MOTIF=yes to enable using pixmaps in indicator icon"
	@${ECHO_MSG} "*"
.endif

MAN1=		xrus.1
DOCS=		FAQ NEWS README* TODO xrus.doc-*

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${PREFIX}/lib/X11/app-defaults/Xrus
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

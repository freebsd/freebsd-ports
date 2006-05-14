# New ports collection makefile for:	bpm
# Date created:				23 July 2004
# Whom:					sethk
#
# $FreeBSD$
#

PORTNAME=	bpm
PORTVERSION=	0.4.1b
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.meowfishies.com/code/bpm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sethk@meowfishies.com
COMMENT=	A graphical BSD ports collection manager

RUN_DEPENDS=	portupgrade:${PORTSDIR}/sysutils/portupgrade \
		gdialog:${PORTSDIR}/x11/zenity

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 desktopfileutils

MAKE_ENV+=	OSTYPE="${OPSYS}"

SUB_FILES=	bpm.desktop

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s|-lintl|-lintl -L${LOCALBASE}/lib|g"
# GnomeVFS needs pthread; bpm may use GnomeVFS (via GtkFileChooser)
	@${REINPLACE_CMD} -e 's|^CFLAGS+=|& ${PTHREAD_CFLAGS}|; \
		s|^LDLIBS+=|& ${PTHREAD_LIBS}|' ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKDIR}/bpm.desktop ${PREFIX}/share/applications/bpm.desktop
	@-update-desktop-database

.include <bsd.port.mk>

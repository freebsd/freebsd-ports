# Created by: sethk
# $FreeBSD$

PORTNAME=	bpm
PORTVERSION=	0.4.1b
PORTREVISION=	19
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.meowfishies.com/code/bpm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Graphical BSD ports collection manager

RUN_DEPENDS=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade \
  		gnomesu:${PORTSDIR}/security/libgnomesu \
		gdialog:${PORTSDIR}/x11/zenity

USES=		desktop-file-utils pkgconfig
USE_GNOME=	gtk20

MAKE_ENV+=	OSTYPE="${OPSYS}"

SUB_FILES=	bpm.desktop

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s|-lintl|-lintl -L${LOCALBASE}/lib|g"
# GnomeVFS needs pthread; bpm may use GnomeVFS (via GtkFileChooser)
	@${REINPLACE_CMD} -e 's|^CFLAGS+=|& ${PTHREAD_CFLAGS}|; \
		s|^LDLIBS+=|& ${PTHREAD_LIBS}|' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|<glib/.*.h>|<glib.h>|g' \
		${WRKSRC}/src/*.h

post-install:
	${INSTALL_DATA} ${WRKDIR}/bpm.desktop ${PREFIX}/share/applications/bpm.desktop

.include <bsd.port.mk>

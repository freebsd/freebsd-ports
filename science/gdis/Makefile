# ex:ts=8
# Ports collection Makefile for:	gdis
# Date created:			Mar 3, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gdis
PORTVERSION=	0.77.0
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.seul.org/pub/gdis/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_MESA=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	main

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|/usr/local/bin|${DATADIR}|g ; \
		 s|gtk-config|${GTK_CONFIG}|g ; \
		 s|-I/usr/local/include||g ; \
		 s|-lgtkgl|-lgtkgl ${PTHREAD_LIBS:S/"//g}|g ; \
		 s|-DGTK_GL|-DGTK_GL ${PTHREAD_CFLAGS}|g' ${WRKSRC}/Makefile
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<sys/dir.h>|<dirent.h>|g ; \
		 s|struct direct|struct dirent|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdis ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gdis.elements ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

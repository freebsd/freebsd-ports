# New ports collection makefile for:	GUI to Direct Connect Text Client
# Date created:				Thu Nov 22 00:34:48 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dctc
PORTVERSION=	0.42
CATEGORIES=	net gnome
MASTER_SITES=	http://ac2i.tzo.com/dctc/
PKGNAMESUFFIX=	-gui
DISTNAME=	dc_gui-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	dctc:${PORTSDIR}/net/dctc
LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit \
		iconv.2:${PORTSDIR}/converters/iconv \
		intl.1:${PORTSDIR}/devel/gettext

USE_GNOMELIBS=	yes
USE_GTK=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnome=${X11BASE} \
		--with-gtk-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

DOC_FILES= COPYING ChangeLog README

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 -x ${PERL} -pi -e \
		's|(hublist)|dc_\1|;s|(\$$\(datadir\))/gnome|\1|; \
		s|include.+<linux/sem.h>|include <sys/ipc.h>\n#include <sys/sem.h>|'
	@${PERL} -pi -e 's|(<stdio.h>.*)$$|\1\n#include <config.h>|' \
		${WRKSRC}/src/init_fnc.c

post-configure:
	@${ECHO} '#include <sys/param.h>' >> ${CONFIGURE_WRKSRC}/config.h
	@${ECHO} '#ifndef SEMVMX' >> ${WRKSRC}/config.h
	@${ECHO} '#define SEMVMX 32767' >> ${WRKSRC}/config.h
	@${ECHO} '#endif' >> ${WRKSRC}/config.h

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}${PKGNAMESUFFIX}
.endfor
.endif

.include <bsd.port.mk>

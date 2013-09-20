# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	comclear
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://lukereeves.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	History cleaner for Netscape Navigator and Communicator

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	GTK1 DOCS

USE_GMAKE=	yes
USE_AUTOTOOLS=	automake14 autoconf213
CONFIGURE_ARGS=	--disable-gtktest

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README
PLIST_FILES=	bin/comclear

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK1}
USE_GNOME+=	gtk12
.else
CONFIGURE_ENV+=	ac_cv_path_GTK_CONFIG=no
.endif

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} comclear ${PREFIX}/bin)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor

.include <bsd.port.mk>

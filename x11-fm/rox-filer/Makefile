# New ports collection makefile for:	rox-filer
# Date created:        13 November 2000
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox-filer
PORTVERSION=	2.10
CATEGORIES=	x11-fm gnome
MASTER_SITES=	SF/rox
DISTNAME=	rox-filer-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A simple and easy to use graphical file manager

RUN_DEPENDS=	${LOCALBASE}/share/mime/packages/freedesktop.org.xml:${PORTSDIR}/misc/shared-mime-info

PLIST_SUB+=	LOCALBASE=${LOCALBASE}

USE_AUTOTOOLS=	autoconf:213
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 sm xaw xproto
USE_GNOME=	atk gconf2 glib20 gnomevfs2 gtk20 libglade2 libidl libxml2 orbit2 pango pkgconfig
HAS_CONFIGURE=	yes

MAN1=		rox.1

.include <bsd.port.pre.mk>

CONFIGURE_ENV=		APP_DIR=${WRKSRC}/ROX-Filer
CONFIGURE_ARGS=		--enable-rox --with-platform=FreeBSD
CONFIGURE_WRKSRC=	${WRKSRC}/ROX-Filer/src
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
ALL_TARGET=

do-install:
	@${MKDIR} ${PREFIX}/apps/ROX-Filer
	@cd ${WRKSRC}/ROX-Filer && ${CP} -r .DirIcon AppInfo.xml AppRun Help Messages Options.xml ROX ROX-Filer images style.css Templates.glade subclasses ${PREFIX}/apps/ROX-Filer
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/ROX-Filer
	@cd ${WRKSRC} && ${CP} -r Choices ${PREFIX}/share/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/Choices
	@${CAT} ${FILESDIR}/rox | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${PREFIX}/bin/rox
	@${CHMOD} 755 ${PREFIX}/bin/rox
	@${INSTALL_MAN} ${WRKSRC}/rox.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/rox.xml ${PREFIX}/share/mime/packages
	@${LOCALBASE}/bin/update-mime-database ${PREFIX}/share/mime
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

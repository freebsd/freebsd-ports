# $FreeBSD$

PORTNAME=	rox-filer
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	SF/rox/rox/${PORTVERSION}
DISTNAME=	rox-filer-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A simple and easy to use graphical file manager

RUN_DEPENDS=	${LOCALBASE}/share/mime/packages/freedesktop.org.xml:${PORTSDIR}/misc/shared-mime-info

PLIST_SUB+=	LOCALBASE=${LOCALBASE}

USE_AUTOTOOLS=	autoconf213
USE_BZIP2=	yes
USE_XORG=	x11 sm xaw xproto
USE_GNOME=	atk gconf2 glib20 gnomevfs2 gtk20 libglade2 libidl libxml2 orbit2 pango
USES=		gmake pkgconfig
HAS_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ENV=		APP_DIR=${WRKSRC}/ROX-Filer
CONFIGURE_ARGS=		--enable-rox --with-platform=FreeBSD
CONFIGURE_WRKSRC=	${WRKSRC}/ROX-Filer/src
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
ALL_TARGET=

post-configure:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
                ${CONFIGURE_WRKSRC}/configure \
                ${CONFIGURE_WRKSRC}/choices.c \
                ${CONFIGURE_WRKSRC}/support.c \
                ${CONFIGURE_WRKSRC}/type.c \
                ${CONFIGURE_WRKSRC}/usericons.c \
                ${CONFIGURE_WRKSRC}/xdgmime.c
	@${TOUCH} ${CONFIGURE_WRKSRC}/config.status

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/apps/ROX-Filer
	cd ${WRKSRC}/ROX-Filer && ${CP} -r .DirIcon AppInfo.xml AppRun Help Messages Options.xml ROX ROX-Filer Templates.ui images style.css subclasses ${STAGEDIR}${PREFIX}/apps/ROX-Filer
	cd ${WRKSRC} && ${CP} -r Choices ${STAGEDIR}${PREFIX}/share/
	${CAT} ${FILESDIR}/rox | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${STAGEDIR}${PREFIX}/bin/rox
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/rox
	${INSTALL_MAN} ${WRKSRC}/rox.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/rox.xml ${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.post.mk>

# New ports collection makefile for:	rox-filer
# Date created:        13 November 2000
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	rox-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A simple and easy to use graphical file manager

RUN_DEPENDS=	${LOCALBASE}/share/mime/packages/freedesktop.org.xml:${PORTSDIR}/misc/shared-mime-info

PLIST_SUB+=	LOCALBASE=${LOCALBASE}

USE_XLIB=	yes
USE_GNOME=	pkgconfig glib20 gtk20 libxml2 gnomevfs2 pango
USE_AUTOCONF_VER=	213
HAS_CONFIGURE=	yes

MAN1=		rox.1

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
BINARIES=	FreeBSD-ix86
.else
BINARIES=	FreeBSD-${ARCH}
.endif

PLIST_SUB=	BINARIES="${BINARIES}"

CONFIGURE_ENV=		APP_DIR=${WRKSRC}/ROX-Filer
CONFIGURE_ARGS=		--enable-rox --with-platform=${BINARIES}
CONFIGURE_WRKSRC=	${WRKSRC}/ROX-Filer/src
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
ALL_TARGET=

do-install:
	@${MKDIR} ${PREFIX}/apps/ROX-Filer
	@cd ${WRKSRC}/ROX-Filer && ${CP} -r .DirIcon  AppInfo.xml AppRun ${BINARIES} Help Messages Options.xml ROX images style.css ${PREFIX}/apps/ROX-Filer
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

# New ports collection makefile for:	rox-filer
# Date created:        13 November 2000
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	rox
PORTVERSION=	2.1.1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=	rox-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A simple and easy to use graphical file manager

RUN_DEPENDS=	${LOCALBASE}/share/mime/packages/freedesktop.org.xml:${PORTSDIR}/misc/shared-mime-info

PLIST_SUB+=	LOCALBASE=${LOCALBASE}
USE_GNOME=	gtk20 pkgconfig libxml2 gnomevfs2

MAN1=		rox.1

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
BINARIES=	FreeBSD-ix86
.else
BINARIES=	FreeBSD-${ARCH}
.endif

PLIST_SUB=	BINARIES="${BINARIES}"

do-build:
	# Run the custom build procedure
	@cd ${WRKSRC} && GTK_CONFIG=${GTK_CONFIG} GLIB_CONFIG=${GLIB_CONFIG} ROX-Filer/AppRun --compile

do-install:
	@${MKDIR} ${PREFIX}/apps/ROX-Filer
	@cd ${WRKSRC}/ROX-Filer && ${CP} -r .DirIcon Action.png Action-it.png AppInfo.xml AppRun ${BINARIES} Help Messages Options.xml ROX images style.css ${PREFIX}/apps/ROX-Filer
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/ROX-Filer
	@cd ${WRKSRC} && ${CP} -r Choices ${PREFIX}/share/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/Choices
	@${CAT} ${FILESDIR}/rox | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${PREFIX}/bin/rox
	@${CHMOD} 755 ${PREFIX}/bin/rox
	@${INSTALL_MAN} ${WRKSRC}/rox.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/rox.xml ${PREFIX}/share/mime/packages
	@${LOCALBASE}/bin/update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>

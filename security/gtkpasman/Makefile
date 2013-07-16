# Created by: Philippe Rocques
# $FreeBSD$
#

PORTNAME=	gtkpasman
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-sources/${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTK+ passwords manager for system and network administrators

RUN_DEPENDS+=	gpgv2:${PORTSDIR}/security/gnupg

USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gtk2
USE_AUTOTOOLS=	automake aclocal autoconf

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

DOCS=		README data/gpasman4.sample
PLIST_FILES=	bin/gtkpasman share/applications/gtkpasman.desktop
ACLOCAL_ARGS?=	--automake-acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal

.if !defined(NOPORTDOCS)
PORTDOCS=	README gpasman4.sample
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/src/Makefile.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkpasman ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/gtkpasman.desktop \
	${PREFIX}/share/applications
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif
	@-update-desktop-database

.include <bsd.port.mk>

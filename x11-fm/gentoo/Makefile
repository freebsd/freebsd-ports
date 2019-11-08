# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	gentoo
PORTVERSION=	0.20.7
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ based, file manager inspired by DirectoryOpus

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk30
USES=		gettext gmake gnome pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"

OPTIONS_DEFINE=	FAM DOCS

FAM_USES=		fam
FAM_CONFIGURE_ENABLE=	fam

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g ; \
		 s|/bin/mount|/sbin/mount|g ; \
		 s|/bin/umount|/sbin/umount|g' ${WRKSRC}/gentoorc.in
	@${REINPLACE_CMD} -e '/^CFLAGS/s|@GENTOO_CFLAGS@|@CFLAGS@|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|#define GTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/odmultibutton.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${STAGEDIR}${MANPREFIX}/man/man1/gentoo.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in BUGS CONFIG-CHANGES CREDITS NEWS README README.NLS README.gtkrc \
	TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/gentoo.1x

.include <bsd.port.mk>

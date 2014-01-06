# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	gentoo
PORTVERSION=	0.19.13
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/ \
		http://mirror.4bit.ws/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Gtk+ based, file manager inspired by DirectoryOpus

OPTIONS_DEFINE=	FAM DOCS

USE_GNOME=	gnomehack gtk20
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MKDIR_P="${MKDIR}"

MAN1=		gentoo.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFAM}
USES+=		fam
.else
CONFIGURE_ARGS+=	--disable-fam
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g ; \
		 s|/bin/mount|/sbin/mount|g ; \
		 s|/bin/umount|/sbin/umount|g' ${WRKSRC}/gentoorc.in
	@${REINPLACE_CMD} -e '/^CFLAGS/s|@GENTOO_CFLAGS@|@CFLAGS@|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|#define GTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/odmultibutton.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${MANPREFIX}/man/man1/gentoo.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in BUGS CONFIG-CHANGES CREDITS NEWS README README.NLS README.gtkrc \
	TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/docs --exclude "gentoo.1x*" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+x
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	gentoo
# Date created:				12 August 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gentoo
PORTVERSION=	0.11.48
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ based, file manager inspired by DirectoryOpus

USE_GNOME=	gtk12
USE_ICONV=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gentoo.1

MYPORTDOCS=	BUGS CONFIG-CHANGES CREDITS NEWS README README.NLS \
		README.gtkrc TODO

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|icons|${DATADIR}/icons|g' ${WRKSRC}/gentoorc.in
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|g' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${MANPREFIX}/man/man1/gentoo.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/docs --exclude "gentoo.1x" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+x
	@${FIND} ${DOCSDIR} -name *.bak -delete
.endif

.include <bsd.port.mk>

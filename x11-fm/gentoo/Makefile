# New ports collection makefile for:	gentoo
# Date created:				12 August 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gentoo
PORTVERSION=	0.11.57
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ based, file manager inspired by DirectoryOpus

OPTIONS=	NLS "Native Language Support" on \
		FAM "File Alteration Monitor Support" off

USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		gentoo.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_FAM)
USE_FAM=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--disable-fam
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CFLAGS = @GENTOO_CFLAGS@|CFLAGS = @CFLAGS@|g ; \
		 s|^MKDIR_P =.*$$|MKDIR_P = ${MKDIR}|g ; \
		 s|^mkdir_p =.*$$|mkdir_p = ${MKDIR}|g'

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${MANPREFIX}/man/man1/gentoo.1
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>

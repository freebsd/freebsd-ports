# New ports collection makefile for:	gentoo
# Date created:				12 August 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gentoo
PORTVERSION=	0.11.55
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk+ based, file manager inspired by DirectoryOpus

USE_GNOME=	gnometarget gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gentoo.1

OPTIONS=	NLS "Native Language Support" on \
		FAM "File Alteration Monitor Support" off

.include <bsd.port.pre.mk>

MYPORTDOCS=	BUGS CONFIG-CHANGES CREDITS NEWS README README.NLS \
		README.gtkrc TODO

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_FAM)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.else
CONFIGURE_ARGS+=	--disable-fam
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CFLAGS = @GENTOO_CFLAGS@|CFLAGS = @CFLAGS@|g ; \
		 s|^mkinstalldirs =.*$$|mkinstalldirs = $$(SHELL) $$(top_srcdir)/mkinstalldirs|g'

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/gentoo.1x ${MANPREFIX}/man/man1/gentoo.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/docs --exclude "gentoo.1x*" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+x
.endif

.include <bsd.port.post.mk>

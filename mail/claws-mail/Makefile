# New ports collection makefile for:	sylpheed-claws
# Date created:		3 January 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	sylpheed-claws
PORTVERSION=	0.7.0
CATEGORIES=	mail news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sylpheed-claws
DISTNAME=	sylpheed-${PORTVERSION}claws

MAINTAINER=	corecode@corecode.ath.cx

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GTK=	yes

CONFIGURE_ARGS=	--program-suffix="-claws" --with-included-gettext \
		--enable-ipv6

CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LIBS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

.if defined(WITH_PIXBUF) || defined(WITH_ALL)
LIB_DEPENDS+=		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
CONFIGURE_ARGS+=	--disable-imlib
.else
USE_IMLIB=		yes
CONFIGURE_ARGS+=	--disable-gdk-pixbuf
.endif
.if defined(WITH_GPGME) || defined(WITH_ALL)
LIB_DEPENDS+=		gpgme.4:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--enable-gpgme
.endif
.if defined(WITH_COMPFACE) || defined(WITH_ALL)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
.else
CONFIGURE_ARGS+=	--disable-compface
.endif
.if defined(WITH_JCONV) || defined(WITH_ALL)
LIB_DEPENDS+=		jconv.0:${PORTSDIR}/japanese/libjconv
.else
CONFIGURE_ARGS+=	--disable-jconv
.endif
.if defined(WITH_PSPELL) || defined(WITH_ALL)
LIB_DEPENDS+=		pspell.4:${PORTSDIR}/textproc/pspell
CONFIGURE_ARGS+=	--enable-pspell
.endif
.if !defined(WITHOUT_SSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may define the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_ALL       Enable all options below"
	@${ECHO} "      WITH_PIXBUF    Enable GDK Pixbuf support"
	@${ECHO} "      WITH_GPGME     Enable GnuPG support using GPGME"
	@${ECHO} "      WITH_COMPFACE  Enable compface (X-Face) support"
	@${ECHO} "      WITH_JCONV     Enable enhanced charset conversion"
	@${ECHO} "      WITH_PSPELL    Enable spell-checking support"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL    Disable OpenSSL support"
	@${ECHO} ""

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/tools/README.sylprint ${WRKSRC}/tools/sylprint.pl
.if defined(NOPORTDOCS)
	@${PERL} -pi -e 's|^(SUBDIRS = .*)manual (.*)|\1\2|' ${WRKSRC}/Makefile.in
.endif

pre-build:
	@${LN} -sf ${LOCALBASE}/bin/${LIBTOOL} ${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
.for i in README README.jp README.claws RELEASE_NOTES.claws TODO TODO.jp tools/README.sylprint
	@${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${INSTALL_MAN} ${WRKSRC}/tools/README ${DOCSDIR}/README.tools
.endif
	@${MKDIR} ${DATADIR}
.for i in eud2gc.py filter_conv.pl gif2xface.pl ldif-to-xml.py newscache_clean.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/${i} ${DATADIR}
.endfor
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/sylpheed-switcher ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/sylprint.pl ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/tools/sylprint.rc ${PREFIX}/etc/sylprint.rc.example
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.png ${PREFIX}/share/pixmaps/sylpheed-claws.png

.include <bsd.port.mk>

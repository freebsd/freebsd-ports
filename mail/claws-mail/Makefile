# New ports collection makefile for:	sylpheed-claws
# Date created:		3 January 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	0.6.6
CATEGORIES=	mail news ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sylpheed-claws
PKGNAMESUFFIX=	-claws
DISTNAME=	sylpheed-${PORTVERSION}claws

MAINTAINER=	corecode@corecode.ath.cx

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GTK=	yes

CONFIGURE_ARGS=	--program-suffix="-claws" --with-included-gettext \
		--enable-ipv6

.if defined(WITH_PIXBUF)
LIB_DEPENDS+=		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
CONFIGURE_ARGS+=	--disable-imlib
.else
USE_IMLIB=		yes
CONFIGURE_ARGS+=	--disable-gdk-pixbuf
.endif
.if defined(WITH_GPGME)
LIB_DEPENDS+=		gpgme.4:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=		gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=	--enable-gpgme
.endif
.if defined(WITH_COMPFACE)
LIB_DEPENDS+=		compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ENV+=		LIBS="-L${X11BASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-compface
.endif
.if defined(WITH_PSPELL)
LIB_DEPENDS+=		pspell.4:${PORTSDIR}/textproc/pspell
CONFIGURE_ARGS+=	--enable-pspell
.endif
.if !defined(WITHOUT_SSL)
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl
.endif

pre-everything::
.if !defined(WITH_PIXBUF)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable GDK Pixbuf support by defining WITH_PIXBUF."
.endif
.if defined(WITH_GPGME)
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: GnuPG support using GPGME is still experimental."
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable GnuPG support using GPGME by defining WITH_GPGME."
	@${ECHO_MSG} "WARNING: GnuPG support is still experimental."
.endif
.if !defined(WITH_COMPFACE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable compface (X-Face) support by defining WITH_COMPFACE."
.endif
.if !defined(WITH_PSPELL)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable pspell support by defining WITH_PSPELL."
.endif
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable OpenSSL support by defining WITHOUT_SSL."
.endif
	@${ECHO_MSG}

pre-build:
	${LN} -sf ${LOCALBASE}/bin/${LIBTOOL} ${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sylpheed-claws
.for i in NEWS README README.claws README.jp RELEASE_NOTES.claws TODO TODO.jp
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/sylpheed-claws
.endfor
.endif
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.png ${PREFIX}/share/pixmaps/sylpheed-claws.png

.include <bsd.port.mk>

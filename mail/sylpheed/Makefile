# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	0.7.0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/

MAINTAINER=	lehmann@ans-netz.de

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-ipv6 --prefix=${PREFIX} --with-included-gettext

.if defined(WITH_PIXBUF)
LIB_DEPENDS+=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
CONFIGURE_ARGS+=--disable-imlib
.else
USE_IMLIB=	yes
CONFIGURE_ARGS+=--disable-gdk-pixbuf
.endif
.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.4:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=--enable-gpgme
.else
CONFIGURE_ARGS+=--disable-gpgme
.endif
.if defined(WITH_COMPFACE)
LIB_DEPENDS+=	compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=--enable-compface
.else
CONFIGURE_ARGS+=--disable-compface
.endif
.if defined(WITH_JCONV)
LIB_DEPENDS+=	jconv.0:${PORTSDIR}/japanese/libjconv
CONFIGURE_ARGS+=--enable-jconv
.else
CONFIGURE_ARGS+=--disable-jconv
.endif
.if defined(WITH_JPILOT)
LIB_DEPENDS+=	expense.1:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=--enable-jpilot
CFLAGS+=	-I${LOCALBASE}/pilot/include
.else
CONFIGURE_ARGS+=	--disable-jpilot
.endif
.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--enable-ssl
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_PIXBUF=yes   Enable GDK Pixbuf support"
	@${ECHO} "      WITH_GPGME=yes    Enable GnuPG support using GPGME."
	@${ECHO} "      WITH_COMPFACE=yes Enable X-Face support."
	@${ECHO} "      WITH_JCONV=yes    Enable Japanese charset conversion"
	@${ECHO} "                        library libjconv."
	@${ECHO} "      WITH_JPILOT=yes   Enable JPilot support."
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL=yes   Disable OpenSSL support."
	@${ECHO} ""

pre-build:
	${LN} -sf ${LOCALBASE}/bin/${LIBTOOL} ${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ChangeLog INSTALL README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${i}.jp ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

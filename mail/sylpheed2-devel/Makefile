# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	0.6.6
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
CONFIGURE_ARGS=	--disable-compface --disable-gdk-pixbuf --enable-ipv6 --prefix=${PREFIX} --with-included-gettext

.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.4:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=--enable-gpgme
.endif
.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--enable-ssl
.endif

PORTDOCS=	ChangeLog INSTALL README TODO

pre-extract:
.if defined(WITH_GPGME)
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: GnuPG support using GPGME is still experimental."
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable GnuPG support using GPGME by defining WITH_GPGME."
	@${ECHO_MSG} "WARNING: GnuPG support is still experimental."
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
	${MKDIR} ${PREFIX}/share/doc/sylpheed
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/sylpheed
	${INSTALL_DATA} ${WRKSRC}/${i}.jp ${PREFIX}/share/doc/sylpheed
.endfor
.endif

.include <bsd.port.mk>

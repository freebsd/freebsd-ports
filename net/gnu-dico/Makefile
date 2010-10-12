# New ports collection makefile for:	gnu dico
# Date created:		27-12-2009
# Whom:			Goran Tal
#
# $FreeBSD$
#

PORTNAME=	dico
PORTVERSION=	2.1
CATEGORIES=	net textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gnu-

MAINTAINER=	goran.tal@gmail.com
COMMENT=	Flexible modular implementation of DICT server

USE_XZ=		yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl:22 libtool:22

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--localstatedir=/var

OPTIONS=	PYTHON	"With PYTHON support" on \
		GUILE	"With GUILE support" on \
		GSASL	"With GSASL support" off \
		LDAP	"With LDAP support" off

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_GUILE)
LIB_DEPENDS+=	guile.20:${PORTSDIR}/lang/guile
PLIST_SUB+=	GUILE=""
.else
CONFIGURE_ARGS+=--without-guile
PLIST_SUB+=	GUILE="@comment "
.endif

.if defined(WITH_GSASL)
LIB_DEPENDS+=	gsasl.13:${PORTSDIR}/security/gsasl
CONFIGURE_ARGS+=--with-gsasl
.else
CONFIGURE_ARGS+=--without-gsasl
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		dico

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
SUB_FILES+=	pkg-message
USE_RC_SUBR=	dicod.sh

post-patch:
	@${REINPLACE_CMD} 's/ENODATA/EIO/' ${WRKSRC}/lib/utf8.c
	@${REINPLACE_CMD} 's/@bindir@/@sbindir@/' ${WRKSRC}/dicod/Makefile.in
	@${REINPLACE_CMD} 's/(bindir)..dir/&\/gdico/' ${WRKSRC}/dico/Makefile.in
	@${REINPLACE_CMD} '/INSTALL.*charset/d' ${WRKSRC}/gnu/Makefile.in

post-install:
	@${INSTALL_DATA} ${FILESDIR}/dicod.conf ${PREFIX}/etc/dicod.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

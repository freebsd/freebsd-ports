# Created by: Goran Tal
# $FreeBSD$

PORTNAME=	dico
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	net textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gnu-

MAINTAINER=	goran.tal@gmail.com
COMMENT=	Flexible modular implementation of DICT server

USE_XZ=		yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl libtool

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var

OPTIONS_DEFINE=	PYTHON GUILE PCRE GSASL PAM LDAP
OPTIONS_DEFAULT=	PYTHON GUILE PCRE
GSASL_DESC=	GSASL support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MGUILE}
LIB_DEPENDS+=	guile.21:${PORTSDIR}/lang/guile
PLIST_SUB+=	GUILE=""
.else
CONFIGURE_ARGS+=--without-guile
PLIST_SUB+=	GUILE="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre
PLIST_SUB+=	PCRE=""
.else
CONFIGURE_ARGS+=--without-pcre
PLIST_SUB+=	PCRE="@comment "
.endif

.if ${PORT_OPTIONS:MGSASL}
LIB_DEPENDS+=	gsasl.16:${PORTSDIR}/security/gsasl
CONFIGURE_ARGS+=--with-gsasl
.else
CONFIGURE_ARGS+=--without-gsasl
.endif

.if ${PORT_OPTIONS:MPAM}
PLIST_SUB+=	PAM=""
CONFIGURE_ARGS+=--enable-pam
.else
PLIST_SUB+=	PAM="@comment "
CONFIGURE_ARGS+=--disable-pam
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		dico

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
SUB_FILES+=	pkg-message
USE_RC_SUBR=	dicod

post-patch:
	@${REINPLACE_CMD} 's/@bindir@/@sbindir@/' ${WRKSRC}/dicod/Makefile.in
	@${REINPLACE_CMD} 's/(bindir)..dir/&\/gdico/' ${WRKSRC}/dico/Makefile.in
	@${REINPLACE_CMD} '/INSTALL.*charset/d' ${WRKSRC}/gnu/Makefile.in

post-install:
	@${INSTALL_DATA} ${FILESDIR}/dicod.conf ${PREFIX}/etc/dicod.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

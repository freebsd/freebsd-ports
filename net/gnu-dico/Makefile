# Created by: Goran Tal
# $FreeBSD$

PORTNAME=	dico
PORTVERSION=	2.7
PORTREVISION=	3
CATEGORIES=	net textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu-

MAINTAINER=	goran.tal@gmail.com
COMMENT=	Flexible modular implementation of DICT server

LIB_DEPENDS=	libltdl.so:devel/libltdl

USE_LDCONFIG=	yes
USES=		tar:xz gmake libtool localbase pkgconfig

GNU_CONFIGURE=	yes

INFO=		dico

PLIST_SUB=	PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message
USE_RC_SUBR=	dicod

OPTIONS_DEFINE=	PYTHON GUILE PCRE GSASL PAM LDAP NLS
OPTIONS_DEFAULT=	PYTHON PCRE
OPTIONS_SUB=	yes
GSASL_DESC=	GSASL support

PYTHON_USES=		python
PYTHON_CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
PYTHON_CONFIGURE_OFF=	--without-python

GUILE_LIB_DEPENDS=	libguile-2.2.so:lang/guile2
GUILE_CONFIGURE_OFF=	--without-guile

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_OFF=	--without-pcre

GSASL_LIB_DEPENDS=	libgsasl.so:security/libgsasl
GSASL_CONFIGURE_WITH=	gsasl

PAM_CONFIGURE_ENABLE=	pam

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_OFF=	--without-ldap

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} 's/@bindir@/@sbindir@/' ${WRKSRC}/dicod/Makefile.in
	@${REINPLACE_CMD} 's/(bindir)..dir/&\/gdico/' ${WRKSRC}/dico/Makefile.in
	@${REINPLACE_CMD} '/INSTALL.*charset/d' ${WRKSRC}/gnu/Makefile.in
	@${REINPLACE_CMD} \
		-e 's/mu_check_lib_save_LIBS/LIBS/' \
		-e 's/python-config/$${PYTHON_CONFIG}/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's/mergesort/xmergesort/' ${WRKSRC}/lib/mergesort.c

post-install:
	${INSTALL_DATA} ${FILESDIR}/dicod.conf ${STAGEDIR}${PREFIX}/etc/dicod.conf.sample

.include <bsd.port.mk>

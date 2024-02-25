PORTNAME=	dico
DISTVERSION=	2.11
PORTREVISION=	2
CATEGORIES=	net textproc
MASTER_SITES=	GNU

MAINTAINER=	info@dikt.tv
COMMENT=	Flexible modular implementation of DICT server
WWW=		https://www.gnu.org/software/dico/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gmake libtool localbase pkgconfig readline tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

INFO=		dico

LDFLAGS+=	-lthr

PLIST_SUB=	PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message
USE_RC_SUBR=	dicod

OPTIONS_DEFINE=	PYTHON GUILE PCRE GSASL PAM LDAP NLS
OPTIONS_DEFAULT=	PYTHON PCRE
OPTIONS_SUB=	yes
GSASL_DESC=	GSASL support

GSASL_USES=		iconv
GSASL_LIB_DEPENDS=	libgsasl.so:security/libgsasl
GSASL_CONFIGURE_WITH=	gsasl

GUILE_USES=		guile:2.2,alias
GUILE_CONFIGURE_WITH=	guile

LDAP_USES=		ldap
LDAP_CONFIGURE_OFF=	--without-ldap

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PAM_CONFIGURE_ENABLE=	pam

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_OFF=	--without-pcre

PYTHON_USES=		python
PYTHON_CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config
PYTHON_CONFIGURE_OFF=	--without-python

post-patch:
	@${REINPLACE_CMD} 's/@bindir@/@sbindir@/' ${WRKSRC}/dicod/Makefile.in
	@${REINPLACE_CMD} \
		-e 's/mu_check_lib_save_LIBS/LIBS/' \
		-e 's/python-config/$${PYTHON_CONFIG}/' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/dicod.conf ${STAGEDIR}${PREFIX}/etc/dicod.conf.sample

.include <bsd.port.mk>

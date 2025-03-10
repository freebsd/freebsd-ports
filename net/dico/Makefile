PORTNAME=	dico
DISTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	net textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible modular implementation of DICT server
WWW=		https://www.gnu.org/software/dico/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gmake iconv libtool localbase ncurses pkgconfig readline tar:xz
USE_LDCONFIG=	yes
USE_RC_SUBR=	dicod
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lthr
SUB_FILES=	pkg-message
INFO=		dico
PLIST_SUB=	VERSION=${DISTVERSION}

OPTIONS_DEFINE=	PYTHON GUILE PCRE GSASL PAM LDAP NLS TK
OPTIONS_DEFAULT=	PYTHON PCRE
OPTIONS_SUB=	yes
GSASL_DESC=	GSASL support

GSASL_LIB_DEPENDS=	libgsasl.so:security/libgsasl
GSASL_CONFIGURE_WITH=	gsasl

GUILE_USES=		guile:2.2,alias
GUILE_CONFIGURE_WITH=	guile

LDAP_USES=		ldap
LDAP_CONFIGURE_OFF=	--without-ldap

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PAM_CONFIGURE_ENABLE=	pam

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_CONFIGURE_OFF=	--without-pcre

PYTHON_USES=		python
PYTHON_CONFIGURE_OFF=	--without-python
PYTHON_CONFIGURE_ENV=	PYTHON_CONFIG=${PYTHON_CMD}-config

TK_USES=		tk
TK_BINARY_ALIAS=	wish=${WISH}

post-patch:
	@${REINPLACE_CMD} 's/@bindir@/@sbindir@/' ${WRKSRC}/dicod/Makefile.in
	@${REINPLACE_CMD} \
		-e 's/mu_check_lib_save_LIBS/LIBS/' \
		-e 's/python-config/$${PYTHON_CONFIG}/' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${FILESDIR}/dicod.conf ${STAGEDIR}${PREFIX}/etc/dicod.conf.sample

.include <bsd.port.mk>

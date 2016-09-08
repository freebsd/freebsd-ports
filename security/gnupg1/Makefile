# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	1.4.21
#PORTREVISION=	0
CATEGORIES=	security
MASTER_SITES=	GNUPG
PKGNAMESUFFIX=	1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The GNU Privacy Guard

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix cpe gmake tar:bzip2
GNU_CONFIGURE=	YES
CPE_VENDOR=	gnupg
.if ${MACHINE_CPU:Mi586}
MACHINE_ARCH=	i586
.endif
CFLAGS:=	${CFLAGS:S/-pipe//g}
INFO=		gnupg1
DOCSDIR=	${PREFIX}/share/doc/gnupg1
PORTDOCS=	*

TEST_TARGET=	check

OPTIONS_DEFINE=	LDAP LIBICONV LIBUSB SUID_GPG NLS CURL DOCS
OPTIONS_DEFAULT=	CURL
OPTIONS_SUB=	yes
LDAP_DESC=	LDAP keyserver interface
LIBICONV_DESC=	use libiconv
LIBUSB_DESC=	use libusb
SUID_GPG_DESC=	install GPG with suid
CURL_DESC=	use libcurl for the keyserver interface

LIBICONV_USES=		iconv
LIBICONV_CONFIGURE_OFF=	--disable-gnupg-iconv

LIBUSB_CONFIGURE_ON=	--with-libusb=${LOCALBASE}
LIBUSB_CONFIGURE_OFF=	--without-libusb

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
#LDAP_CONFIGURE_ENV+=	LDFLAGS="-L/usr/lib"
LDAP_CONFIGURE_OFF=	--disable-ldap

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	--with-libcurl=${LOCALBASE}
# Work around a GnuPG configure buglet
CURL_CONFIGURE_ENV=	_libcurl_config=${LOCALBASE}/bin/curl-config
CURL_CONFIGURE_OFF=	--without-libcurl

.include <bsd.port.options.mk>

.if ${CC} == "clang" || ${OSVERSION} >= 1000024
CFLAGS:=	${CFLAGS:S/$/ -std=c89/}
.if (${ARCH} == "i386")
CFLAGS:=	${CFLAGS:S/$/ -fheinous-gnu-extensions/}
.endif
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in DETAILS FAQ HACKING OpenPGP
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ABOUT-NLS AUTHORS BUGS COPYING INSTALL NEWS PROJECTS \
	README THANKS TODO VERSION
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MSUID_GPG}
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/gpg
.endif

.include <bsd.port.mk>

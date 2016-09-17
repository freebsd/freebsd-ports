# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	1.4.21
CATEGORIES=	security
MASTER_SITES=	GNUPG
PKGNAMESUFFIX=	1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	The GNU Privacy Guard

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	gnupg

USES=		charsetfix cpe gmake tar:bzip2
GNU_CONFIGURE=	YES

INFO=		gnupg1
DOCSDIR=	${PREFIX}/share/doc/gnupg1
PORTDOCS=	*

TEST_TARGET=	check

OPTIONS_DEFINE=	CURL DOCS LDAP LIBICONV LIBUSB NLS SUID_GPG
OPTIONS_DEFAULT=CURL
OPTIONS_SUB=	yes

CURL_DESC=	use libcurl for the keyserver interface
LDAP_DESC=	LDAP keyserver interface
LIBICONV_DESC=	use libiconv
LIBUSB_DESC=	use libusb
SUID_GPG_DESC=	install GPG with suid

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl=${LOCALBASE}
# Work around a GnuPG configure buglet
CURL_CONFIGURE_ENV=	_libcurl_config=${LOCALBASE}/bin/curl-config

LIBICONV_USES=		iconv
LIBICONV_CONFIGURE_ENABLE=	gnupg-iconv

LIBUSB_CONFIGURE_WITH=	libusb=${LOCALBASE}

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap=${LOCALBASE}

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if ${CC} == "clang" || ${OSVERSION} >= 1000024
CFLAGS:=	${CFLAGS:S/$/ -std=c89/}
.if (${ARCH} == "i386")
CFLAGS:=	${CFLAGS:S/$/ -fheinous-gnu-extensions/}
.endif
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in DETAILS FAQ HACKING OpenPGP
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ABOUT-NLS AUTHORS BUGS COPYING INSTALL NEWS PROJECTS \
	README THANKS TODO VERSION
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-SUID_GPG-on:
	${CHMOD} u+s ${STAGEDIR}${PREFIX}/bin/gpg

.include <bsd.port.mk>

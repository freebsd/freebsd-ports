# New ports collection makefile for:	gnupg
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.4.10
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gnupg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The GNU Privacy Guard

USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
.if ${MACHINE_CPU:Mi586}
MACHINE_ARCH=	i586
.endif
CFLAGS:=	${CFLAGS:S/-pipe//g}
MAN1=		gpg.1 gpgv.1 gpg.ru.1 gpg-zip.1
MAN7=		gnupg.7
INFO=		gnupg1
DOCSDIR=	${PREFIX}/share/doc/gnupg1
LATEST_LINK=	gnupg1

PORTDOCS=	*

OPTIONS=	LDAP "LDAP keyserver interface" off \
		LIBICONV "use libiconv" off \
		LIBUSB "use libusb" off \
		SUID_GPG "install GPG with suid" off \
		NLS "Native Language Support" on \
		CURL "use libcurl for the keyserver interface" on

.include <bsd.port.pre.mk>

.if defined(WITH_LIBICONV)
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.endif

.if defined(WITH_LIBUSB)
CONFIGURE_ARGS+=	--with-libusb=${LOCALBASE}
. if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
. endif
.else
CONFIGURE_ARGS+=	--without-libusb
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
PLIST_SUB+=	WITH_LDAP=""
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
#CONFIGURE_ENV+=	LDFLAGS="-L/usr/lib"
.else
PLIST_SUB+=	WITH_LDAP="@comment "
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	YES
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE}
# Work around a GnuPG configure buglet
CONFIGURE_ENV+=	_libcurl_config=${LOCALBASE}/bin/curl-config
.else
CONFIGURE_ARGS+=--without-libcurl
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in DETAILS FAQ HACKING OpenPGP
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.for i in ABOUT-NLS AUTHORS BUGS COPYING INSTALL NEWS PROJECTS \
	README THANKS TODO VERSION
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if defined(WITH_SUID_GPG)
	${CHMOD} u+s ${PREFIX}/bin/gpg
.endif

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.post.mk>

# New ports collection makefile for:	gnupg
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	2.0.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gnupg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The GNU Privacy Guard

BUILD_DEPENDS=	libassuan>=1.0.1:${PORTSDIR}/security/libassuan
LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		ksba.17:${PORTSDIR}/security/libksba \
		pth.20:${PORTSDIR}/devel/pth

CONFLICTS=	gnupg-devel-[0-9]*

USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_ICONV=	YES
USE_LDCONFIG=	YES
USE_GETTEXT=	YES
CONFIGURE_TARGET=# empty
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info --mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--enable-nls
MAN1=		gpg2.1 gpgsm.1 gpgv2.1 gpg-agent.1 scdaemon.1 watchgnupg.1 \
		gpgconf.1 gpg-preset-passphrase.1 gpg-connect-agent.1 \
		gpgparsemail.1 symcryptrun.1 gpgsm-gencert.sh.1
MAN8=		addgnupghome.8 applygnupgdefaults.8
INFO=		gnupg

OPTIONS=	LDAP "LDAP keyserver interface" off \
		SCDAEMON "Enable Smartcard daemon (with libusb)" off \
		CURL "Use the real curl library (worked around if no)" on \
		GPGSM "Enable GPGSM" on
#OPTIONS+=	NLS "National Language Support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GPGSM)
CONFIGURE_ARGS+=--disable-gpgsm
PLIST_SUB+=	GPGSM="@comment "
.else
RUN_DEPENDS=	dirmngr:${PORTSDIR}/security/dirmngr
WITH_LDAP=	YES
PLIST_SUB+=	GPGSM=""
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

#.if defined(WITH_NLS)
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
#.else
#CONFIGURE_ARGS+=--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.endif

.if defined(WITH_SCDAEMON)
CONFIGURE_ARGS+=--enable-scdaemon
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
PLIST_SUB+=	SCDAEMON=""
.else
CONFIGURE_ARGS+=--disable-scdaemon
PLIST_SUB+=	SCDAEMON="@comment "
.endif

.if defined(WITHOUT_CURL)
CONFIGURE_ARGS+=--without-libcurl
.else
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE}
.endif

verify:	checksum
	gpg2 --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

pre-configure:
	${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

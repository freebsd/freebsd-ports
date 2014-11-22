# $FreeBSD$

PORTNAME=	gnupg
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gnupg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The GNU Privacy Guard

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libassuan.so:${PORTSDIR}/security/libassuan \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libksba.so:${PORTSDIR}/security/libksba \
		libnpth.so:${PORTSDIR}/devel/npth
BUILD_DEPENDS=	libgpg-error>=1.11:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	pinentry>0:${PORTSDIR}/security/pinentry

GNU_CONFIGURE=	YES
USES=		gmake iconv tar:bzip2
USE_LDCONFIG=	YES
CONFIGURE_ARGS+=	--enable-symcryptrun --enable-gpgsm
CONFLICTS=	gnupg-2.0.*

OPTIONS_DEFINE=		LDAP SCDAEMON KDNS NLS DOCS SUID_GPG
LDAP_DESC=		LDAP keyserver interface
SCDAEMON_DESC=		Enable Smartcard daemon (with libusb)
KDNS_DESC=		Use DNS CERT helper
SUID_GPG_DESC=		Install GPG with suid
OPTIONS_DEFAULT=	#
NO_OPTIONS_SORT=	YES
OPTIONS_SUB=		YES
# In jail, SUID is required to avoid warning (security.bsd.unprivileged_mlock sysctl is not used in jail).

DOCS_CONFIGURE_ENABLE=	doc
KDNS_LIB_DEPENDS=	libadns.so:${PORTSDIR}/dns/adns
KDNS_CONFIGURE_ON=	--with-adns=${LOCALBASE}
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SCDAEMON_CONFIGURE_ENABLE=	scdaemon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO=		gnupg
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ! ${PORT_OPTIONS:MKDNS}
CONFIGURE_SUB=	-e '/GPGKEYS_KDNS=/s/".*"/""/'
.endif

verify:	checksum
	gpg2 --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

post-patch:
	@${REINPLACE_CMD} -e "s@-lpthread@${PTHREAD_LIBS}@g" ${CONFIGURE_SUB} \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "/#include <utmp.h>/d" \
		${WRKSRC}/tools/symcryptrun.c

.include <bsd.port.mk>

# New ports collection makefile for:	gnupg
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/%SUBDIR%/ \
		http://ftp.planetmirror.com/pub/gnupg/%SUBDIR%/ \
		http://sunsite.dk/pub/security/gcrypt/%SUBDIR%/ \
		ftp://pgp.iijlab.net/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/gnupg/&,} \
		ftp://ftp.demon.nl/pub/mirrors/gnupg/%SUBDIR%/
MASTER_SITE_SUBDIR=	gnupg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-tiger
CONFIGURE_TARGET=	--build ${MACHINE_ARCH}-portbld-freebsd${OSREL}
.if ${MACHINE_CPU:Mi586}
MACHINE_ARCH=	i586
.endif
CFLAGS:=	${CFLAGS:S/-pipe//g}
MAN1=		gpg.1 gpgv.1
MAN7=		gnupg.7

.include <bsd.port.pre.mk>

.if defined(WITH_LIBICONV) || exists(${PREFIX}/lib/libiconv.so)
LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv
.endif
.if defined(WITH_LDAP) || exists(${PREFIX}/lib/libldap.so)
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2
PLIST_SUB+=	WITH_LDAP=""
.else
PLIST_SUB+=	WITH_LDAP="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gnupg
.for i in DETAILS FAQ HACKING OpenPGP
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/gnupg
.endfor
.for i in ABOUT-NLS AUTHORS BUGS COPYING INSTALL NEWS PROJECTS \
	README THANKS TODO VERSION
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/gnupg
.endfor
.endif
.if defined(WITH_SUID_GPG)
	${CHMOD} u+s ${PREFIX}/bin/gpg
.endif
	@${CAT} ${PKGMESSAGE}

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.post.mk>

# New ports collection makefile for:	gnupg
# Date created:		Sep 30, 1998
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.2.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	gnupg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	The GNU Privacy Guard

USE_BZIP2=	YES

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	YES
.endif

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build ${MACHINE_ARCH}-portbld-freebsd${OSREL}
.if ${MACHINE_CPU:Mi586}
MACHINE_ARCH=	i586
.endif
CFLAGS:=	${CFLAGS:S/-pipe//g}
.if !defined(WITHOUT_NLS)
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif
MAN1=		gpg.1 gpgv.1
MAN7=		gnupg.7
# Workaround for 1.2.5 distribution.
# Refer: http://lists.gnupg.org/pipermail/gnupg-announce/2004q3/000173.html
INSTALL_TARGET=	install mkinstalldirs=`pwd`/scripts/mkinstalldirs

.include <bsd.port.pre.mk>

.if defined(WITH_LIBICONV) || exists(${PREFIX}/lib/libiconv.so)
USE_ICONV=	yes
.endif
.if defined(WITH_LDAP) || exists(${PREFIX}/lib/libldap.so)
USE_OPENLDAP=	yes
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
.if ${OSVERSION} < 500019
	@${CAT} ${PKGMESSAGE}
.else
PKGMESSAGE=	/nonexistent
.endif

check:
	(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.post.mk>

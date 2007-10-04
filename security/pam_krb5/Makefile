# Ports collection Makefile for:	pam_krb5
# Date created:				11/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		pam_krb5
PORTVERSION=		1.3.r7
PORTREVISION=		3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}
DISTNAME=		${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=		cy@FreeBSD.org
COMMENT=		A Pluggable Authentication Module for Kerberos 5

MAN5=			pam_krb5.5 pam_krb5afs.5
MAN8=			pam_krb5.8 pam_krb5afs.8

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

IGNORE=			FreeBSD 5.x already ships with its own version of pam_krb5

.if defined(PACKAGE_BUILDING)
KRB5_IMPL=		mit
.endif

.if defined(KRB5_IMPL) && ${KRB5_IMPL} == heimdal
LIB_DEPENDS=		krb5.21:${PORTSDIR}/security/heimdal
.if defined(HEIMDAL_HOME)
KRB5_DIR?=		${HEIMDAL_HOME}
.endif
.elif defined(KRB5_IMPL) && ${KRB5_IMPL} == mit
LIB_DEPENDS=		krb5.3:${PORTSDIR}/security/krb5
.if defined(KRB5_HOME)
KRB5_DIR?=		${KRB5_HOME}
.endif
.else
IGNORE=			You must define KRB5_IMPL to be \"mit\" or \"heimdal\"
.endif

MANDIR=			${MANPREFIX}/man
PREFIX=			/usr
MANPREFIX=		/usr/share
MANDIR=			${PREFIX}/share/man
KRB5_DIR?=		${LOCALBASE}
CONFIGURE_ENV=		CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=		--with-krb5="${KRB5_DIR}"	\
			--with-pamdir="${PREFIX}/lib"	\
			--with-man-sect=8		\
			--without-krbafs

post-install:
	cd ${WRKSRC} && ${GMAKE} install-man

.include <bsd.port.mk>

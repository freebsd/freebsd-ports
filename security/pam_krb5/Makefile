# Ports collection Makefile for:	pam_krb5
# Date created:				11/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		pam_krb5
PORTVERSION=		4.2
CATEGORIES=		security
MASTER_SITES=		http://archives.eyrie.org/software/kerberos/
DISTNAME=		pam-krb5-${PORTVERSION:S/.r/-rc/}

MAINTAINER=		cy@FreeBSD.org
COMMENT=		A Pluggable Authentication Module for Kerberos 5

MAN5=			pam_krb5.5

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.if defined(KRB5_IMPL) && ${KRB5_IMPL} == heimdal
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
MANDIR=			${PREFIX}/share/man
KRB5_DIR?=		${LOCALBASE}
CONFIGURE_ENV=		CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=		--with-krb5="${KRB5_DIR}"

post-install:
	cd ${WRKSRC} && ${GMAKE} install-man

.include <bsd.port.mk>

# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=		pam_krb5
PORTVERSION=		4.6
CATEGORIES=		security
MASTER_SITES=		http://archives.eyrie.org/software/kerberos/ \
			http://archives.eyrie.org/software/ARCHIVE/pam-krb5/
DISTNAME=		pam-krb5-${PORTVERSION:S/.r/-rc/}

MAINTAINER=		cy@FreeBSD.org
COMMENT=		A Pluggable Authentication Module for Kerberos 5

CONFLICTS=		pam_krb5-rh-2.*

USES=		perl5 gmake
GNU_CONFIGURE=		yes

.if defined(KRB5_IMPL) && ${KRB5_IMPL} == heimdal
.if defined(HEIMDAL_HOME)
KRB5_DIR?=		${HEIMDAL_HOME}
.endif
.elif defined(KRB5_IMPL) && ${KRB5_IMPL} == mit
LIB_DEPENDS=		libkrb5.so:${PORTSDIR}/security/krb5
.if defined(KRB5_HOME)
KRB5_DIR?=		${KRB5_HOME}
.endif
.else
IGNORE=			you must define KRB5_IMPL to be "mit" or "heimdal"
.endif

MANDIR=			${STAGEDIR}${MANPREFIX}/man
MANDIR=			${STAGEDIR}${PREFIX}/share/man
KRB5_DIR?=		${LOCALBASE}
CONFIGURE_ARGS=		--with-krb5="${KRB5_DIR}"

post-install:
	cd ${WRKSRC} && ${MAKE_CMD} install-man DESTDIR=${STAGEDIR}

.include <bsd.port.mk>

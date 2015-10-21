# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=		pam_krb5
PORTVERSION=		4.7
CATEGORIES=		security
MASTER_SITES=		http://archives.eyrie.org/software/kerberos/ \
			http://archives.eyrie.org/software/ARCHIVE/pam-krb5/
DISTNAME=		pam-krb5-${PORTVERSION:S/.r/-rc/}

MAINTAINER=		cy@FreeBSD.org
COMMENT=		Pluggable Authentication Module for Kerberos 5

CONFLICTS=		pam_krb5-rh-2.*

GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-strip
USES=			gmake libtool perl5
USE_PERL5=		build

OPTIONS_SINGLE=		LINK
OPTIONS_SINGLE_LINK=	MIT HEIMDAL_BASE HEIMDAL_PORT
OPTIONS_DEFAULT=	MIT
MIT_DESC=		Link against MIT Kerberos
HEIMDAL_PORT_DESC=	Link against Heimdal in ports Kerberos
HEIMDAL_BASE_DESC=	Link against Heimdal in base Kerberos

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHEIMDAL_BASE}
USES+=			gssapi:base
.elif ${PORT_OPTIONS:MHEIMDAL_PORT}
USES+=			gssapi:heimdal
.if defined(HEIMDAL_HOME)
KRB5_DIR?=		${HEIMDAL_HOME}
.else
KRB5_DIR?=		${LOCALBASE}
.endif
CONFIGURE_ARGS+=	--with-krb5="${KRB5_DIR}"
CONFIGURE_ENV=		PATH_KRB5_CONFIG=${KRB5_DIR}/bin/krb5-config
.elif ${PORT_OPTIONS:MMIT}
USES+=			gssapi:mit
LIB_DEPENDS=		libkrb5.so.3:${PORTSDIR}/security/krb5
.if defined(KRB5_HOME)
KRB5_DIR?=		${KRB5_HOME}
.else
KRB5_DIR?=		${LOCALBASE}
.endif
CONFIGURE_ARGS+=	--with-krb5="${KRB5_DIR}"
.else
IGNORE=			 KRB5_IMPL option must be set
.endif

MANDIR=			${STAGEDIR}${MANPREFIX}/man

post-install:
	cd ${WRKSRC} && ${MAKE_CMD} install-man DESTDIR=${STAGEDIR}

.include <bsd.port.post.mk>

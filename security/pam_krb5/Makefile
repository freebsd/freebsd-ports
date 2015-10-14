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

OPTIONS_SINGLE=		LINK
OPTIONS_SINGLE_LINK=	MIT HEIMDAL
OPTIONS_DEFAULT=	MIT
MIT_DESC=		Link against MIT Kerberos
HEIMDAL_DESC=		Link against Heimdal Kerberos

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHEIMDAL}
.if defined(HEIMDAL_HOME)
KRB5_DIR?=		${HEIMDAL_HOME}
.endif
.elif ${PORT_OPTIONS:MMIT}
LIB_DEPENDS=		libkrb5.so.3:${PORTSDIR}/security/krb5
.if defined(KRB5_HOME)
KRB5_DIR?=		${KRB5_HOME}
.endif
.else
IGNORE=			you must define KRB5_IMPL to be "mit" or "heimdal"
.endif

MANDIR=			${STAGEDIR}${MANPREFIX}/man
KRB5_DIR?=		${LOCALBASE}
CONFIGURE_ARGS=		--with-krb5="${KRB5_DIR}"

post-install:
	cd ${WRKSRC} && ${MAKE_CMD} install-man DESTDIR=${STAGEDIR}

.include <bsd.port.post.mk>

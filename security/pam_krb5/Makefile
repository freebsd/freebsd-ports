# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=		pam_krb5
PORTVERSION=		4.8
CATEGORIES=		security
MASTER_SITES=		http://archives.eyrie.org/software/kerberos/ \
			http://archives.eyrie.org/software/ARCHIVE/pam-krb5/
DISTNAME=		pam-krb5-${PORTVERSION:S/.r/-rc/}

MAINTAINER=		cy@FreeBSD.org
COMMENT=		Pluggable Authentication Module for Kerberos 5

LICENSE=		BSD3CLAUSE GPLv1+
LICENSE_COMB=		dual
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			gmake libtool perl5
USE_PERL5=		build

CONFLICTS=		pam_krb5-rh-2.*
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-krb5="${GSSAPIBASEDIR}" \
			--with-krb5-include="${GSSAPIINCDIR}" \
			--with-krb5-lib="${GSSAPILIBDIR}"
CONFIGURE_ENV=		PATH_KRB5_CONFIG="${KRB5CONFIG}"
INSTALL_TARGET=		install-strip

OPTIONS_SINGLE=		LINK
OPTIONS_SINGLE_LINK=	MIT HEIMDAL_BASE HEIMDAL_PORT
OPTIONS_DEFAULT=	MIT

MIT_DESC=		Link against MIT Kerberos
HEIMDAL_PORT_DESC=	Link against Heimdal in ports Kerberos
HEIMDAL_BASE_DESC=	Link against Heimdal in base Kerberos

MIT_USES=		gssapi:mit
HEIMDAL_PORT_USES=	gssapi:heimdal
HEIMDAL_BASE_USES=	gssapi:base

post-install:
	cd ${WRKSRC} && ${MAKE_CMD} install-man DESTDIR=${STAGEDIR}

.include <bsd.port.mk>

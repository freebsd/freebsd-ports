# Created by: Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
# $FreeBSD$

PORTNAME=	dovecot-pigeonhole
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://pigeonhole.dovecot.org/releases/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${PORTVERSION}

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Sieve plugin for the Dovecot 'deliver' LDA and LMTP

LICENSE=	LGPL21

BUILD_DEPENDS=	dovecot>=2.3.4:mail/dovecot
RUN_DEPENDS=	dovecot>=2.3.4:mail/dovecot

DOVECOTVERSION=	2.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--without-dovecot-install-dirs \
		--docdir=${DOCSDIR} \
		--with-dovecot="${LOCALBASE}/lib/dovecot"
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		compiler:c11 libtool ssl
USE_LDCONFIG=	${PREFIX}/lib/dovecot

CONFLICTS_INSTALL=	dovecot-pigeonhole04

OPTIONS_DEFINE=	DOCS LDAP MANAGESIEVE
OPTIONS_DEFAULT=MANAGESIEVE GSSAPI_NONE

OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_NONE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_SUB=	yes

GSSAPI_DESC=		GSSAPI Support (*MUST MATCH* mail/dovecot)
GSSAPI_NONE_DESC=	Build without GSSAPI support
GSSAPI_BASE_DESC=	Use GSSAPI from base
GSSAPI_HEIMDAL_DESC=	Use Heimdal GSSAPI from security/heimdal
GSSAPI_MIT_DESC=	Use MIT GSSAPI from security/krb5

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CONFIGURE_OFF=	${GSSAPI_CONFIGURE_ARGS}
BUILD_FAIL_MESSAGE=	Ensure that ${PORTNAME}'s GSSAPI backend is the same as dovecot2 (make config).

MANAGESIEVE_DESC=		ManageSieve support
MANAGESIEVE_CONFIGURE_WITH=	managesieve

LDAP_CONFIGURE_WITH=	ldap
LDAP_CPPFLAGS=		-I${LOCALBASE}/include
LDAP_LDFLAGS=		-L${LOCALBASE}/lib
LDAP_USE=		OPENLDAP=yes

PORTDOCS=	sieve/extensions/* sieve/plugins/* sieve/locations/*

post-patch:
	@${REINPLACE_CMD} -E '\
	s!^(install-data-am:) install-sieve_docDATA!\1!; \
		s!^(uninstall-am:) uninstall-sieve_docDATA!\1!;' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>

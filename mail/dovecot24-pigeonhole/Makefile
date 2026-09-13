PORTNAME=	pigeonhole
DISTVERSION=	2.4.5
CATEGORIES=	mail
MASTER_SITES=	https://pigeonhole.dovecot.org/releases/2.4/
PKGNAMEPREFIX=	dovecot24-
PKGNAMESUFFIX=	${FLAVOR:Ndefault:C/.+/-${FLAVOR}/}
DISTNAME=	dovecot-pigeonhole-${DISTVERSION}

MAINTAINER=	jordan@ostreff.info
COMMENT=	Sieve plugin for the Dovecot '2.4' IMAP and POP3 server
WWW=		https://pigeonhole.dovecot.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

# Dependencies
BUILD_DEPENDS=	dovecot24${PKGNAMESUFFIX}>=2.4.5:mail/dovecot24@${FLAVOR}
RUN_DEPENDS=	dovecot24${PKGNAMESUFFIX}>=2.4.5:mail/dovecot24@${FLAVOR}

# Flavors
FLAVORS=	default mysql pgsql sqlite3 ldap cdb
FLAVOR?=	${FLAVORS:[1]}

USES=		cpe libtool localbase pkgconfig python:build,test ssl
CPE_VENDOR=	dovecot
CPE_PRODUCT=	pigeonhole
USE_LDCONFIG=	${PREFIX}/lib/dovecot

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-dovecot=${LOCALBASE}/lib/dovecot
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	dovecot-pigeonhole dovecot-pigeonhole-* \
			dovecot24-pigeonhole dovecot24-pigeonhole-*

# Options definitions
# For FLAVOR=ldap, LDAP support is mandatory and must not be
# deselectable, so the LDAP option is only exposed for the other flavors.
.if ${FLAVOR} == ldap
OPTIONS_DEFINE=		DOCS EXAMPLES MANAGESIEVE
.else
OPTIONS_DEFINE=		DOCS EXAMPLES LDAP MANAGESIEVE
.endif
OPTIONS_DEFAULT=	DOCS MANAGESIEVE
OPTIONS_SUB=		yes

# Options descriptions
.if ${FLAVOR} != ldap
LDAP_DESC=		LDAP protocol support
.endif
MANAGESIEVE_DESC=	ManageSieve support

# Options helpers
.if ${FLAVOR} != ldap
LDAP_USES=			ldap
LDAP_CONFIGURE_WITH=		ldap
.endif
MANAGESIEVE_CONFIGURE_WITH=	managesieve

.include <bsd.port.options.mk>

# FLAVOR=ldap always builds with LDAP support enabled. Set the same
# USES/CONFIGURE_ARGS/PLIST_SUB values here that the LDAP option would
# set for non-flavor users, so both paths produce an identical pkg-plist.
.if ${FLAVOR} == ldap
USES+=			ldap
CONFIGURE_ARGS+=	--with-ldap
PLIST_SUB+=		LDAP="" \
			NO_LDAP="@comment "
.endif

.include <bsd.port.mk>

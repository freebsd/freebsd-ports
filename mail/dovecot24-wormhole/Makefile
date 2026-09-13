PORTNAME=	wormhole
DISTVERSION=	0.14
CATEGORIES=	mail
MASTER_SITES=	https://codeberg.org/errror/wormhole/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	dovecot24-
PKGNAMESUFFIX=	${FLAVOR:Ndefault:C/.+/-${FLAVOR}/}

MAINTAINER=	trashcan@ellael.org
COMMENT=	Wormhole plugin for the Dovecot '2.4' IMAP and POP3 server
WWW=		https://people.mpi-klsb.mpg.de/~pcernko/wormhole.shtml

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

# Dependencies
BUILD_DEPENDS=	dovecot24${PKGNAMESUFFIX}>=2.4.5:mail/dovecot24@${FLAVOR}
RUN_DEPENDS=	dovecot24${PKGNAMESUFFIX}>=2.4.5:mail/dovecot24@${FLAVOR}

# Flavors
FLAVORS=	default mysql pgsql sqlite3 ldap cdb
FLAVOR?=	${FLAVORS:[1]}

USES=		libtool pkgconfig python:build,test ssl

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC} -D_GNU_SOURCE
LDFLAGS+=	-L${OPENSSLLIB}

CONFLICTS_INSTALL=	dovecot dovecot-mysql dovecot-pgsql dovecot-sqlite3 \
			dovecot-ldap dovecot-cdb

.if ${FLAVOR} == default
CONFLICTS_INSTALL +=	dovecot24-wormhole-mysql dovecot24-wormhole-pgsql \
			dovecot24-wormhole-sqlite3 dovecot24-wormhole-ldap \
			dovecot24-wormhole-cdb
.elif ${FLAVOR} == mysql
CONFLICTS_INSTALL +=	dovecot24-wormhole dovecot24-wormhole-pgsql \
			dovecot24-wormhole-sqlite3 dovecot24-wormhole-ldap \
			dovecot24-wormhole-cdb
.elif ${FLAVOR} == pgsql
CONFLICTS_INSTALL +=	dovecot24-wormhole dovecot24-wormhole-mysql \
			dovecot24-wormhole-sqlite3 dovecot24-wormhole-ldap \
			dovecot24-wormhole-cdb
.elif ${FLAVOR} == sqlite3
CONFLICTS_INSTALL +=	dovecot24-wormhole dovecot24-wormhole-mysql \
			dovecot24-wormhole-pgsql dovecot24-wormhole-ldap \
			dovecot24-wormhole-cdb
.elif ${FLAVOR} == ldap
CONFLICTS_INSTALL +=	dovecot24-wormhole dovecot24-wormhole-mysql \
			dovecot24-wormhole-pgsql dovecot24-wormhole-sqlite3 \
			dovecot24-wormhole-cdb
.elif ${FLAVOR} == cdb
CONFLICTS_INSTALL +=	dovecot24-wormhole dovecot24-wormhole-mysql \
			dovecot24-wormhole-pgsql dovecot24-wormhole-sqlite3 \
			dovecot24-wormhole-ldap
.endif

.include <bsd.port.mk>

# Created by: clive
# $FreeBSD$

PORTNAME=	nullmailer
PORTVERSION=	1.13
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/ \
		http://untroubled.org/nullmailer/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MTA for hosts which relay to a fixed set of smart relays

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LOCALSTATEDIR=	/var/spool

USERS=		nullmail
GROUPS=		nullmail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${LOCALSTATEDIR}

USE_CXXSTD=	gnu++98

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-install pkg-deinstall pkg-message

PLIST_SUB=	LOCALSTATEDIR=${LOCALSTATEDIR} NULLMAIL_USER=${USERS}
SUB_LIST=	LOCALSTATEDIR=${LOCALSTATEDIR} NULLMAIL_USER=${USERS}

OPTIONS_DEFINE=	GNUTLS

GNUTLS_CONFIGURE_ENABLE=tls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		localbase:ldflags
GNUTLS_LDFLAGS=		-lgnutls

post-install:
	${INSTALL_DATA} -c ${FILESDIR}/remotes.sample ${STAGEDIR}${ETCDIR}
	${ECHO} 'hostname' > ${STAGEDIR}${ETCDIR}/me.sample

.include <bsd.port.mk>

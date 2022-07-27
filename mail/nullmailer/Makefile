PORTNAME=	nullmailer
PORTVERSION=	2.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/ \
		http://untroubled.org/nullmailer/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MTA for hosts which relay to a fixed set of smart relays

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_CXXSTD=	gnu++98
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${LOCALSTATEDIR}

SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST=	LOCALSTATEDIR=${LOCALSTATEDIR} NULLMAIL_USER=${USERS}

USERS=		nullmail
GROUPS=		nullmail

PLIST_SUB=	LOCALSTATEDIR=${LOCALSTATEDIR} NULLMAIL_USER=${USERS}

OPTIONS_DEFINE=	GNUTLS

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		localbase:ldflags
GNUTLS_CONFIGURE_ENABLE=tls
GNUTLS_LDFLAGS=		-lgnutls

LOCALSTATEDIR=	/var

post-install:
	${INSTALL_DATA} -c ${FILESDIR}/remotes.sample ${STAGEDIR}${ETCDIR}
	${ECHO} 'hostname' > ${STAGEDIR}${ETCDIR}/me.sample

.include <bsd.port.mk>

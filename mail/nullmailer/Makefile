# Created by: clive
# $FreeBSD$

PORTNAME=	nullmailer
PORTVERSION=	1.13
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/nullmailer/ \
		http://untroubled.org/nullmailer/archive/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MTA for hosts which relay to a fixed set of smart relays

LICENSE=	GPLv2

LOCALSTATEDIR=	/var/spool

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		nullmail
GROUPS=		nullmail
NULLMAIL_UID=	522
NULLMAIL_GID=	522

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=${LOCALSTATEDIR}

USE_SUBMAKE=	yes

USE_RC_SUBR=	${PORTNAME}
SUB_FILES+=	pkg-install pkg-deinstall pkg-message

PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	LOCALSTATEDIR=${LOCALSTATEDIR} NULLMAIL_USER=${USERS}
SUB_LIST+=	LOCALSTATEDIR=${LOCALSTATEDIR} NULLMAIL_USER=${USERS}

MAN1=	nullmailer-inject.1 sendmail.1
MAN7=	nullmailer.7
MAN8=	nullmailer-queue.8 nullmailer-send.8


OPTIONS_DEFINE=	GNUTLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnutls
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--enable-tls
.else
CONFIGURE_ARGS+=--disable-tls
.endif

post-install:
	@cd ${WRKSRC} && ${MAKE} install-root

	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${INSTALL_DATA} -c ${FILESDIR}/remotes.sample ${ETCDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

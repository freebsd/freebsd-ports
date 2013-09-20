# Created by: Alexander Timoshenko <gonzo@univ.kiev.ua>
# $FreeBSD$

PORTNAME=	ejabberd
PORTVERSION=	2.1.13
CATEGORIES=	net-im
MASTER_SITES=	http://www.process-one.net/downloads/ejabberd/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/COPYING

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USERS=		ejabberd
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
USES=		iconv gmake pkgconfig
USE_RC_SUBR=	${PORTNAME}
NOPRECIOUSMAKEVARS=	yes

OPTIONS_DEFINE=	ODBC PAM

MAKE_ENV=	PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS+=--localstatedir=/var --with-openssl=${OPENSSLBASE}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message pkg-install
SUB_LIST=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		USERS=${USERS} GROUPS=${GROUPS}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

NO_STAGE=	yes
.include <bsd.port.pre.mk>

USE_OPENSSL=	yes

.include "${PORTSDIR}/Mk/bsd.openssl.mk"

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=--enable-odbc
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=--enable-pam
PLIST_SUB+=	PAM=""
.else
PLIST_SUB+=	PAM="@comment "
.endif

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=	NOPORTDOCS=${NOPORTDOCS}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/configure

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
	@${FIND} ${PREFIX}/lib/erlang/lib/${DISTNAME} -type f -print0 | ${XARGS} -0 ${CHOWN} ${SHAREOWN}:${SHAREGRP}

.if ${PORT_OPTIONS:MPAM}
	${CHMOD} 4750 ${PREFIX}/lib/erlang/lib/${DISTNAME}/priv/bin/epam
	${CHOWN} root:ejabberd ${PREFIX}/lib/erlang/lib/${DISTNAME}/priv/bin/epam
	${INSTALL} -m 444 ${FILESDIR}/pam_ejabberd ${PREFIX}/etc/pam.d/ejabberd
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

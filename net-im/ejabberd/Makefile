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
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

USERS=		ejabberd
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
USES=		iconv gmake pkgconfig
USE_RC_SUBR=	${PORTNAME}
NOPRECIOUSMAKEVARS=	yes

OPTIONS_DEFINE=	ODBC PAM DOCS

MAKE_ENV=	PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS+=--localstatedir=/var --with-openssl=${OPENSSLBASE} --with-expat=${LOCALBASE}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message pkg-install
SUB_LIST=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		USERS=${USERS} GROUPS=${GROUPS} SHAREMODE=${SHAREMODE} \
		SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

OPTIONS_SUB=		yes
PAM_CONFIGURE_ENABLE=	pam
ODBC_CONFIGURE_ENABLE=	odbc
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=yes

USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MPAM}
	${INSTALL} -m 444 ${FILESDIR}/pam_ejabberd ${STAGEDIR}${PREFIX}/etc/pam.d/ejabberd
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

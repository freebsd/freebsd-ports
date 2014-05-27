# Created by: Alexander Timoshenko <gonzo@univ.kiev.ua>
# $FreeBSD$

PORTNAME=	ejabberd
PORTVERSION=	14.05
CATEGORIES=	net-im
MASTER_SITES=	http://www.process-one.net/downloads/${PORTNAME}/${PORTVERSION}/:p1 \
		http://distfiles.pirateparty.in/%SUBDIR%/:deps \
		${MASTER_SITE_LOCAL:S/$/:deps/}
MASTER_SITE_SUBDIR=	ashish/:deps
DISTFILES+=	${PORTNAME}-${PORTVERSION}.tgz:p1 ejabberd-deps-0.tar.xz:deps

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		git:${PORTSDIR}/devel/git
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang
LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libyaml.so:${PORTSDIR}/textproc/libyaml

USERS=		ejabberd
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_RC_SUBR=	${PORTNAME}
NOPRECIOUSMAKEVARS=	yes

OPTIONS_DEFINE=	ODBC PAM DOCS HTTP STUN JSON MYSQL PGSQL LAGER ICONV
OPTIONS_DEFAULT=	LAGER ICONV

MAKE_ENV=	PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS+=--localstatedir=/var --with-openssl=${OPENSSLBASE} --with-expat=${LOCALBASE}
MAKE_ARGS=	"CPPFLAGS=${CPPFLAGS}" "CFLAGS=${CFLAGS}" "LDFLAGS=${LDFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message pkg-install
SUB_LIST=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		USERS=${USERS} GROUPS=${GROUPS} SHAREMODE=${SHAREMODE} \
		SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP}

OPTIONS_SUB=		yes
HTTP_DESC=	HTTP support
STUN_DESC=	STUN support
LAGER_DESC=	LAGER logger
PAM_CONFIGURE_ENABLE=	pam
ODBC_CONFIGURE_ENABLE=	odbc
LAGER_CONFIGURE_ENABLE=	lager
HTTP_CONFIGURE_ENABLE=	http
JSON_CONFIGURE_ENABLE=	json
STUN_CONFIGURE_ENABLE=	stun
MYSQL_CONFIGURE_ENABLE=	mysql
PGSQL_CONFIGURE_ENABLE=	pgsql
ICONV_CONFIGURE_ENABLE=	iconv
ICONV_USES=		iconv
ICONV_LDFLAGS=		${ICONV_LIB}
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=yes

USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${LN} -s ${WRKDIR}/deps ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MPAM}
	${INSTALL} -m 444 ${FILESDIR}/pam_ejabberd ${STAGEDIR}${PREFIX}/etc/pam.d/ejabberd
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

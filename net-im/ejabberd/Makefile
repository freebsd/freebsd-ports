# Created by: Alexander Timoshenko <gonzo@univ.kiev.ua>
# $FreeBSD$

PORTNAME=	ejabberd
PORTVERSION=	15.06
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.process-one.net/downloads/${PORTNAME}/${PORTVERSION}/:p1 \
		http://distfiles.pirateparty.in/ashish/:deps \
		LOCAL/ashish:deps
DISTFILES+=	${DISTNAME}.tgz:p1 ejabberd-deps-3.tar.xz:deps

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
USES=		cpe gmake pkgconfig
USE_RC_SUBR=	${PORTNAME}
NOPRECIOUSMAKEVARS=	yes
CPE_VENDOR=	process-one

OPTIONS_DEFINE=	ODBC PAM DOCS JSON MYSQL PGSQL LAGER ICONV RIAK REDIS SQLITE TOOLS
OPTIONS_DEFAULT=	LAGER ICONV

MAKE_ENV=	PORTVERSION=${PORTVERSION}
CONFIGURE_ARGS+=--localstatedir=/var
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
LAGER_DESC=	LAGER logger
RIAK_DESC=	Riak database support
TOOLS_DESC=	Build development tools
PAM_CONFIGURE_ENABLE=	pam
ODBC_CONFIGURE_ENABLE=	odbc
LAGER_CONFIGURE_ENABLE=	lager
JSON_CONFIGURE_ENABLE=	json
MYSQL_CONFIGURE_ENABLE=	mysql
PGSQL_CONFIGURE_ENABLE=	pgsql
RIAK_CONFIGURE_ENABLE=	riak
ICONV_CONFIGURE_ENABLE=	iconv
REDIS_CONFIGURE_ENABLE=	redis
SQLITE_CONFIGURE_ENABLE=sqlite
TOOLS_CONFIGURE_ENABLE=	tools
SQLITE_USE=		SQLITE=yes
ICONV_USES=		iconv:wchar_t
ICONV_LDFLAGS=		${ICONV_LIB}
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=yes

USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${LN} -s ${WRKDIR}/deps ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC}/deps/p1_iconv/rebar.config

post-install:
.if ${PORT_OPTIONS:MPAM}
	${INSTALL} -m 444 ${FILESDIR}/pam_ejabberd ${STAGEDIR}${PREFIX}/etc/pam.d/ejabberd
.endif
.for _file in p1_tls_drv.so expat_erl.so p1_yaml.so esip_drv.so p1_sha.so jiffy.so ezlib_drv.so iconv.so stringprep.so
	-@[ -f ${STAGEDIR}${PREFIX}/lib/erlang/lib/ejabberd-${PORTVERSION}/priv/lib/${_file} ] && ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/ejabberd-${PORTVERSION}/priv/lib/${_file}
.endfor

.include <bsd.port.post.mk>

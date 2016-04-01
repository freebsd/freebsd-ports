# $FreeBSD$

PORTNAME=	stanchion
PORTVERSION=	2.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://s3.amazonaws.com/downloads.basho.com/stanchion/${PORTVERSION:R}/${PORTVERSION}/ \
	http://downloads.basho.com.s3.amazonaws.com/stanchion/${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Open source database cluster control for Riak

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/riak-erlang/bin/erlc:lang/erlang-riak

USES=		gmake readline
USE_RC_SUBR=	stanchion

USERS=		stanchion
GROUPS=		riak

STANCHION_CONFDIR?=	${PREFIX}/etc/stanchion
STANCHION_DBDIR?=	/var/db/stanchion
STANCHION_HOMEDIR?=	${PREFIX}/lib/stanchion
STANCHION_LIBDIR?=	${PREFIX}/lib/stanchion/lib
STANCHION_LOGDIR?=	/var/log/stanchion

PLIST_SUB+=	STANCHION_CONFDIR=${STANCHION_CONFDIR} \
	STANCHION_DBDIR=${STANCHION_DBDIR} \
	STANCHION_HOMEDIR=${STANCHION_HOMEDIR} \
	STANCHION_LIBDIR=${STANCHION_LIBDIR} \
	STANCHION_LOGDIR=${STANCHION_LOGDIR} \
	USERS=${USERS} \
	GROUPS=${GROUPS}

ALL_TARGET=	rel
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	PATH=${LOCALBASE}/lib/riak-erlang/bin:${PATH}

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/rel/vars.config

do-install:
	${MKDIR} ${STAGEDIR}${STANCHION_CONFDIR}
	${MKDIR} ${STAGEDIR}${STANCHION_DBDIR}
	${MKDIR} ${STAGEDIR}${STANCHION_LOGDIR}
	${INSTALL_DATA} ${WRKSRC}/rel/stanchion/etc/stanchion.conf ${STAGEDIR}${STANCHION_CONFDIR}/stanchion.conf
	${INSTALL_DATA} ${WRKSRC}/rel/stanchion/etc/advanced.config ${STAGEDIR}${STANCHION_CONFDIR}/advanced.config
	${INSTALL_DATA} ${WRKSRC}/rel/stanchion/etc/cert.pem ${STAGEDIR}${STANCHION_CONFDIR}/cert.pem
	${INSTALL_DATA} ${WRKSRC}/rel/stanchion/etc/key.pem ${STAGEDIR}${STANCHION_CONFDIR}/key.pem
	(cd ${WRKSRC}/rel/stanchion/lib/ && ${COPYTREE_BIN} . ${STAGEDIR}${STANCHION_LIBDIR})
	(cd ${WRKSRC}/rel/stanchion/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/sbin/)
	(cd ${WRKSRC}/rel/stanchion/releases && ${COPYTREE_SHARE} . ${STAGEDIR}${STANCHION_HOMEDIR}/releases)
	${CP} -R ${WRKSRC}/rel/stanchion/erts-* ${STAGEDIR}${STANCHION_HOMEDIR}

post-install:
	(cd ${STAGEDIR}${STANCHION_HOMEDIR}; ${FIND} releases -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/stanchion/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${STANCHION_HOMEDIR}; ${FIND} erts-* -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn  \
		| ${AWK} '{print "lib/stanchion/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${STANCHION_HOMEDIR}; ${FIND} erts-* -type d -empty \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "@dir lib/stanchion/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${STANCHION_LIBDIR}; ${FIND} . -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/stanchion/lib/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${STANCHION_LIBDIR}; ${FIND} . -type d -empty \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "@dir lib/stanchion/lib/"$$2 }' >> ${TMPPLIST})

.include <bsd.port.mk>

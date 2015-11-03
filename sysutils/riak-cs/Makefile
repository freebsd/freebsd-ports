# $FreeBSD$

PORTNAME=	riak-cs
PORTVERSION=	2.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://s3.amazonaws.com/downloads.basho.com/riak-cs/${PORTVERSION:R}/${PORTVERSION}/ \
	http://downloads.basho.com.s3.amazonaws.com/riak-cs/${PORTVERSION:R}/${PORTVERSION}/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Open source, distributed, S3 interface to Riak KV

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/riak-erlang/bin/erlc:${PORTSDIR}/lang/erlang-riak

USES=		gmake readline
USE_RC_SUBR=	riak-cs

USERS=		riakcs
GROUPS=		riak

RIAKCS_CONFDIR?=${PREFIX}/etc/riak-cs
RIAKCS_DBDIR?=	/var/db/riak-cs
RIAKCS_HOMEDIR?=${PREFIX}/lib/riak-cs
RIAKCS_LIBDIR?=	${PREFIX}/lib/riak-cs/lib
RIAKCS_LOGDIR?=	/var/log/riak-cs

PLIST_SUB+=	RIAKCS_CONFDIR=${RIAKCS_CONFDIR} \
	RIAKCS_DBDIR=${RIAKCS_DBDIR} \
	RIAKCS_HOMEDIR=${RIAKCS_HOMEDIR} \
	RIAKCS_LIBDIR=${RIAKCS_LIBDIR} \
	RIAKCS_LOGDIR=${RIAKCS_LOGDIR} \
 	USERS=${USERS} \
	GROUPS=${GROUPS}

ALL_TARGET=	rel
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	PATH=${LOCALBASE}/lib/riak-erlang/bin:${PATH}

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/rel/vars.config

do-install:
	${MKDIR} ${STAGEDIR}${RIAKCS_CONFDIR}
	${MKDIR} ${STAGEDIR}${RIAKCS_DBDIR}
	${MKDIR} ${STAGEDIR}${RIAKCS_LOGDIR}
	${INSTALL_DATA} ${WRKSRC}/rel/riak-cs/etc/riak-cs.conf ${STAGEDIR}${RIAKCS_CONFDIR}/riak-cs.conf
	${INSTALL_DATA} ${WRKSRC}/rel/riak-cs/etc/advanced.config ${STAGEDIR}${RIAKCS_CONFDIR}/advanced.config
	${INSTALL_DATA} ${WRKSRC}/rel/riak-cs/etc/cert.pem ${STAGEDIR}${RIAKCS_CONFDIR}/cert.pem
	${INSTALL_DATA} ${WRKSRC}/rel/riak-cs/etc/key.pem ${STAGEDIR}${RIAKCS_CONFDIR}/key.pem
	(cd ${WRKSRC}/rel/riak-cs/lib/ && ${COPYTREE_BIN} . ${STAGEDIR}${RIAKCS_LIBDIR})
	(cd ${WRKSRC}/rel/riak-cs/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/sbin/)
	(cd ${WRKSRC}/rel/riak-cs/lib/basho-patches && ${COPYTREE_SHARE} . ${STAGEDIR}${RIAKCS_LIBDIR}/basho-patches)
	(cd ${WRKSRC}/rel/riak-cs/releases && ${COPYTREE_SHARE} . ${STAGEDIR}${RIAKCS_HOMEDIR}/releases)
	${CP} -R ${WRKSRC}/rel/riak-cs/erts-* ${STAGEDIR}${RIAKCS_HOMEDIR}

post-install:
	(cd ${STAGEDIR}${RIAKCS_HOMEDIR}; ${FIND} releases -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak-cs/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${RIAKCS_HOMEDIR}; ${FIND} erts-* -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn  \
		| ${AWK} '{print "lib/riak-cs/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${RIAKCS_HOMEDIR}; ${FIND} erts-* -type d -empty \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "@dir lib/riak-cs/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${RIAKCS_LIBDIR}; ${FIND} . -type f \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "lib/riak-cs/lib/"$$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}${RIAKCS_LIBDIR}; ${FIND} . -type d -empty \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn | ${SED} -e 's/^/lib\//' \
		| ${AWK} '{print "@dir lib/riak-cs/lib/"$$2 }' >> ${TMPPLIST})

.include <bsd.port.mk>

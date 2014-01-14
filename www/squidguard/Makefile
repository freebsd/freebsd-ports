# $FreeBSD$

PORTNAME=	squidGuard
PORTVERSION=	1.4
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://www.squidguard.org/Downloads/:a \
		http://www.squidguard.org/Downloads/Contrib/:b
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:a \
		squidGuard-1.4-quoted_string_support.diff:b \
		squidGuard-1.4-dnsbl.patch:b
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	A fast redirector for squid

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BDB=	40+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db-inc=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR} \
		--with-sg-config=${ETCDIR}/${PORTNAME}.conf \
		--with-sg-dbhome=${DATADIR} \
		--with-sg-logdir=${LOGDIR} \
		--exec-prefix=${PREFIX}
CPPFLAGS+=	-I${PREFIX}/include -I${LOCALBASE}/include

SQUID_UID?=	squid
SQUID_GID?=	squid
PLIST_SUB+=	SQUID_UID='${SQUID_UID}' SQUID_GID='${SQUID_GID}'

DATADIR?=	/var/db/${PORTNAME}
ETCDIR=		${PREFIX}/etc/squid
_DATADIR=	${WRKDIR}/data
LOGDIR?=	/var/log/${PORTNAME}
PLIST_SUB+=	LOGDIR="${LOGDIR}"

SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

OPTIONS_DEFINE=		DNS_BL DOCS EXAMPLES LDAP QUOTE_STRING
OPTIONS_SINGLE=		SV
OPTIONS_SINGLE_SV=	SQUID27 SQUID32 SQUID33
OPTIONS_DEFAULT=	SQUID27

EXAMPLES_DESC=	Install sample blacklists
DNS_BL_DESC=	Enable DNS based blacklists
QUOTE_STRING_DESC=	Add quoted string patch
SQUID27_DESC=	Depend on Squid 2.7.x
SQUID32_DESC=	Depend on Squid 3.2.x
SQUID33_DESC=	Depend on Squid 3.3.x

OPTIONS_SUB=		yes
SQUID27_RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid
SQUID32_RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid32
SQUID33_RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid33
LDAP_CONFIGURE_ON=	--with-ldap
LDAP_CONFIGURE_OFF=	--without-ldap
LDAP_LDFLAGS=		-L${LOCALBASE}/lib
LDAP_USE=		OPENLDAP=yes

.include <bsd.port.options.mk>

pre-fetch:
	@if [ ${SQUID_UID} = "squid" -o ${SQUID_GID} = "squid" ] ; then \
		${ECHO_MSG} "===>  SQUID_UID is set to \"${SQUID_UID}\" and SQUID_GID is set to \"${SQUID_GID}\"." ; \
		${ECHO_MSG} "      To change this specify them with your make arguments, e.g." ; \
		${ECHO_MSG} "      make SQUID_UID=nobody SQUID_GID=nogroup" ; \
	fi

post-patch:
	@${REINPLACE_CMD} \
		-e 's,-ldb,-l${BDB_LIB_NAME},' ${WRKSRC}/configure
	@if [ "${BDB_LIB_NAME}" = "db-4.2" ] ; then \
		${REINPLACE_CMD} -E -e 's,(db_version),\1_4002,g' \
			${WRKSRC}/configure ; \
	fi
.if ${PORT_OPTIONS:MQUOTE_STRING}
	${PATCH} -d ${WRKSRC} --forward --quiet -p2 <${DISTDIR}/squidGuard-1.4-quoted_string_support.diff
.endif
.if ${PORT_OPTIONS:MDNS_BL}
	${PATCH} -d ${WRKSRC} --forward --quiet -p1 <${DISTDIR}/squidGuard-1.4-dnsbl.patch
.endif

post-build:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "===>    Preparing blacklists"
	@${MKDIR} ${_DATADIR}
	@${TAR} -C ${_DATADIR} --exclude *.diff -pxzf \
		${WRKSRC}/samples/dest/blacklists.tar.gz
	@${MV} -f ${_DATADIR}/blacklists/README ${WRKDIR}/README.blacklists
	@${MV} -f ${_DATADIR}/blacklists/* ${_DATADIR}/
	@${RM} -r ${_DATADIR}/blacklists
.endif

pre-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "===>   Installing sample blacklists"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/blacklists
	@(cd ${_DATADIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/blacklists)
	@${INSTALL_DATA} ${WRKDIR}/README.blacklists ${STAGEDIR}${EXAMPLESDIR}
	@${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${STAGEDIR}${EXAMPLESDIR}/blacklists
	@${CHMOD} -R 550 ${STAGEDIR}${EXAMPLESDIR}/blacklists
	@${ECHO_MSG} "       -> Sample blacklists installed in ${EXAMPLESDIR}/blacklists"
.endif
	@${ECHO_MSG} "===>   Installing sample configuration file"
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${SED} -e "s|@sg_dbhome@|${EXAMPLESDIR}/blacklists|" -e "s|@sg_logdir@|${LOGDIR}|" \
		${WRKSRC}/samples/sample.conf.in \
		>${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample ; \
	${ECHO_MSG} "       -> Sample configuration file installed in: ${ETCDIR}" ; \

post-install:
	@${ECHO_MSG} "===>   Installing ${PORTNAME} documentation"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for i in ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/README
	@${INSTALL_DATA} ${WRKSRC}$i ${STAGEDIR}${DOCSDIR}
. endfor
	@${ECHO_MSG} "       -> Documentation installed in: ${DOCSDIR}"
	@${MKDIR} ${STAGEDIR}${LOGDIR}
	@${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${STAGEDIR}${LOGDIR}

.include <bsd.port.mk>

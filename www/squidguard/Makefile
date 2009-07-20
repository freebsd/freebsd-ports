# New ports collection makefile for:    squidGuard
# Date created:        5 June 2000
# Whom:                dl@tyfon.net
#
# $FreeBSD$
#

PORTNAME=	squidGuard
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.squidguard.org/Downloads/

MAINTAINER=	mad@madpilot.net
COMMENT=	A fast redirector for squid

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

USE_BDB=	3+
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db-inc=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR} \
		--with-sg-config=${PREFIX}/etc/squid/${PORTNAME}.conf \
		--with-sg-dbhome=${DATADIR} \
		--with-sg-logdir=${LOGDIR} \
		--exec-prefix=${PREFIX}

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${PREFIX}/include"

CFGINPUT=	${.CURDIR}/files/sgcfg.in

SQUID_UID?=	squid
SQUID_GID?=	squid

DATADIR?=	/var/db/${PORTNAME}
SAMPLE_BL_DIR=	${DATADIR}.sample
PLIST_SUB+=	SAMPLE_BL_DIR=${SAMPLE_BL_DIR}
_DATADIR=	${WRKDIR}/data
LOGDIR?=	/var/log

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PORTNAME=${PORTNAME} \
		SAMPLE_BL_DIR=${SAMPLE_BL_DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	SAMPLE_BL	"Install sample blacklists" On \
		LDAP		"Enable LDAP support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--with-ldap
USE_OPENLDAP=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if defined(WITHOUT_SAMPLE_BL)
INSTALL_BL=	no
PLIST_SUB+=	BLACKLIST="@comment "
.else
.if !exists(${DATADIR})
INSTALL_BL=	yes
.else
INSTALL_BL=	no
.endif
PLIST_SUB+=	BLACKLIST=""
.endif

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

post-build:
.if !defined(WITHOUT_SAMPLE_BL)
	@${ECHO_MSG} "===>   Building blacklists"
	${MKDIR} ${_DATADIR}
	@${TAR} -C ${_DATADIR} --exclude *.diff -pxzf \
		${WRKSRC}/samples/dest/blacklists.tar.gz
	@${MV} -f ${_DATADIR}/blacklists/README ${WRKDIR}/README.blacklists
	@${MV} -f ${_DATADIR}/blacklists/* ${_DATADIR}/
	@${RM} -r ${_DATADIR}/blacklists
.endif

pre-install:
#
# Install blacklists
#
.if !defined(WITHOUT_SAMPLE_BL)
	@${MKDIR} ${SAMPLE_BL_DIR}
	@${CP} -Rpf ${_DATADIR}/* ${SAMPLE_BL_DIR}
	@${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${SAMPLE_BL_DIR}
	${CHMOD} -R 550 ${SAMPLE_BL_DIR}
.endif
.if ${INSTALL_BL} == "yes"
	@${ECHO_MSG} "===>   Installing blacklists"
	@${MKDIR} ${DATADIR}
	@${CP} -Rpf ${_DATADIR}/* ${DATADIR}/
	@${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${DATADIR}
	@${CHMOD} -R 550 ${DATADIR}
	@${ECHO_MSG} "       -> Blacklists installed in: ${DATADIR}"
.else
	@${ECHO_MSG} "===>   Found existing datadirectory - skipping blacklist installation"
.endif

#
# Create sample configuration file
#
	@if [ ! -f "${PREFIX}/etc/squid/${PORTNAME}.conf" ] ; then \
		${ECHO_MSG} "===>   Installing sample configuration file" ; \
		BLACKLIST_DIRS=`(cd ${DATADIR} && ${FIND} . -type d | \
		    ${SED} '/^\.$$/d; s/^\.\//!/' | ${XARGS} ${ECHO_CMD})`; \
		for I in `${ECHO_CMD} $${BLACKLIST_DIRS} | ${SED} 's/!//g'`; do \
			${ECHO_CMD} "dest $${I} {"; \
			${TEST} -f ${DATADIR}/$${I}/domains && \
				${ECHO_CMD} "	domainlist $${I}/domains"; \
			${TEST} -f ${DATADIR}/$${I}/urls && \
				${ECHO_CMD} "	urllist $${I}/urls"; \
			${TEST} -f ${DATADIR}/$${I}/expressions && \
				${ECHO_CMD} "	expressionlist $${I}/expressions"; \
			${ECHO_CMD} "}"; \
		done > ${WRKDIR}/${PORTNAME}.conf.dests ; \
		${SED} -e "s|DATADIR|${DATADIR}|" -e "s|LOGDIR|${LOGDIR}|" \
			-e "s|BLACKLIST_DIRS|$${BLACKLIST_DIRS}|;" \
			-e "/DEST_CLASSES/r ${WRKDIR}/${PORTNAME}.conf.dests" \
			${CFGINPUT} | \
			${SED} "/DEST_CLASSES/d" > \
			${PREFIX}/etc/squid/${PORTNAME}.conf.sample ; \
		${CHOWN} ${SQUID_UID}:${SQUID_GID} \
			 ${PREFIX}/etc/squid/${PORTNAME}.conf.sample ; \
		${ECHO_MSG} "       -> Sample configuration file installed in: ${PREFIX}/etc/squid" ; \
	else \
		${ECHO_MSG} "===>   Existing configuration file found - sample not installed" ; \
	fi

#
# Create blacklist databases (assume fresh install if we only have a
#  sample config)
#
.if ${INSTALL_BL} == "yes"
	@${ECHO_MSG} "===>   Creating blacklist databases" ; \
	${WRKSRC}/src/${PORTNAME} -d -c \
		${PREFIX}/etc/squid/${PORTNAME}.conf.sample -C all ; \
	${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${DATADIR} ; \
	${FIND} ${DATADIR} -type f -name *.db -exec ${CHMOD} 660 {} \; ; \
	${ECHO_MSG} "       -> Blacklist databases installed in: ${DATADIR}"
.else
	${ECHO_MSG} "===>   Existing configuration file found - blacklist databases not created"
.endif

post-install:
#
# Install documentation
#
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing ${PORTNAME} documentation"
	-@${MKDIR} ${DOCSDIR}
.for i in ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/README
	@${INSTALL_DATA} ${WRKSRC}$i ${DOCSDIR}
.endfor
	@if [ -f ${WRKDIR}/README.blacklists ] ; then \
		${INSTALL_DATA} ${WRKDIR}/README.blacklists ${DOCSDIR} ; \
	fi
	@${ECHO_MSG} "       -> Documentation installed in: ${DOCSDIR}"
.endif

.if !exists(${LOGDIR})
	@${MKDIR} ${LOGDIR}
	@${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${LOGDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:    squidGuard
# Date created:        5 June 2000
# Whom:                dl@tyfon.net
#
# $FreeBSD$
#

PORTNAME=	squidGuard
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ftp.teledanmark.no/pub/www/proxy/squidGuard/ \
		ftp://ftp.teledanmark.no/pub/www/proxy/squidGuard/ \
		http://web01.ux.tyfon.net/ports/distfiles/

MAINTAINER=	ports@tyfon.net
COMMENT=	A fast redirector for squid

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

USE_SIZE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db-inc=${LOCALBASE}/include/db3 \
		--with-db-lib=${LOCALBASE}/lib \
		--with-sg-config=${PREFIX}/etc/squid/${PORTNAME}.conf \
		--with-sg-dbhome=${DATADIR} \
		--with-sg-logdir=${LOGDIR}

CFGINPUT=	files/sgcfg.in

SQUID_UID?=	nobody
SQUID_GID?=	nogroup

DATADIR?=	/var/db/${PORTNAME}
LOGDIR?=	/var/log

PLIST:=		${WRKDIR}/PLIST
PLIST_SUB=	DATADIR=${DATADIR}

pre-fetch:
	@if [ ${SQUID_UID} = "nobody" -o ${SQUID_GID} = "nogroup" ] ; then \
		${ECHO_MSG} "===>  SQUID_UID is set to \"${SQUID_UID}\" and SQUID_GID is set to \"${SQUID_GID}\"." ; \
		${ECHO_MSG} "      To change this specify them with your make arguments, e.g." ; \
		${ECHO_MSG} "      make SQUID_UID=squid SQUID_GID=squid" ; \
	fi

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}

### 	Install blacklists

.if !exists(${DATADIR})
	@${ECHO_MSG} "===>   Installing blacklists"
	@${MKDIR} -p ${DATADIR}
	@${TAR} -C ${DATADIR} --exclude *.diff -pxzf ${WRKSRC}/samples/dest/blacklists.tar.gz
	@${MV} -f ${DATADIR}/blacklists/README ${WRKDIR}/README.blacklists
	@${MV} -f ${DATADIR}/blacklists/* ${DATADIR}/
	@${RM} -r ${DATADIR}/blacklists
	@${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${DATADIR}
	@${CHMOD} -R 550 ${DATADIR}
	@${CAT} ${PKGDIR}/pkg-plist.blacklist >> ${PLIST}
	@${ECHO_MSG} "       -> Blacklists installed in: ${DATADIR}"
.else
	@${ECHO_MSG} "===>   Found existing datadirectory - skipping blacklist installation"
.endif

###     Create sample configuration file

	@if [ ! -f "${PREFIX}/etc/squid/${PORTNAME}.conf" ] ; then \
		${ECHO_MSG} "===>   Installing sample configuration file" ; \
		BLACKLIST_DIRS=`(cd ${DATADIR} && ${FIND} . -type d | ${SED} '/^\.$$/d; s/^\.\//!/' | ${XARGS} ${ECHO_CMD})`; \
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
		${SED} "s|DATADIR|${DATADIR}|;s|LOGDIR|${LOGDIR}|;s|BLACKLIST_DIRS|$${BLACKLIST_DIRS}|;/DEST_CLASSES/r ${WRKDIR}/${PORTNAME}.conf.dests" \
			${CFGINPUT} | \
			${SED} "/DEST_CLASSES/d" > \
			${PREFIX}/etc/squid/${PORTNAME}.conf.sample ; \
		${CHOWN} ${SQUID_UID}:${SQUID_GID} ${PREFIX}/etc/squid/${PORTNAME}.conf.sample ; \
		${ECHO_MSG} "       -> Sample configuration file installed in: ${PREFIX}/etc/squid" ; \
	else \
		${ECHO_MSG} "===>   Existing configuration file found - sample not installed" ; \
	fi

###	Create blacklist databases (assume fresh install if we only have a sample config)

	@if [ ! -f "${PREFIX}/etc/squid/${PORTNAME}.conf" -a \
		-f "${PREFIX}/etc/squid/${PORTNAME}.conf.sample" ] ; then \
		${ECHO_MSG} "===>   Creating blacklist databases" ; \
		${WRKSRC}/src/${PORTNAME} -d -c ${PREFIX}/etc/squid/${PORTNAME}.conf.sample -C all ; \
		${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${DATADIR} ; \
		${FIND} ${DATADIR} -type f -name *.db -exec ${CHMOD} 660 {} \; ; \
		${ECHO_MSG} "       -> Blacklist databases installed in: ${DATADIR}" ; \
	else \
		${ECHO_MSG} "===>   Existing configuration file found - blacklist databases not created" ; \
	fi

post-install:

###     Install documentation

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing ${PORTNAME} documentation"
	-@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/README
	@${INSTALL_DATA} ${WRKSRC}$i ${PREFIX}/share/doc/${PORTNAME}
.endfor
	@if [ -f ${WRKDIR}/README.blacklists ] ; then \
		${INSTALL_DATA} ${WRKDIR}/README.blacklists ${PREFIX}/share/doc/${PORTNAME} ; \
	fi
	@${ECHO_MSG} "       -> Documentation installed in: ${PREFIX}/share/doc/${PORTNAME}"
.endif

.if !exists(${LOGDIR})
	@${MKDIR} ${LOGDIR}
	@${CHOWN} -R ${SQUID_UID}:${SQUID_GID} ${LOGDIR}
.endif

###	View short howto message

	@${ECHO_MSG} " "
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "= In order to activate ${PORTNAME} you have to edit squid.conf"
	@${ECHO_MSG} "= To the contain \"redirect_program	${PREFIX}/bin/${PORTNAME}\""
	@${ECHO_MSG} "= and create a configuration file for ${PORTNAME}."
	@${ECHO_MSG} "="
	@${ECHO_MSG} "= To activate the changes do a ${PREFIX}/sbin/squid -k reconfigure"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} " "

.include <bsd.port.mk>

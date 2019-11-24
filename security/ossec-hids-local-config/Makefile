# $FreeBSD$

PKGNAMESUFFIX?=	-${OSSEC_TYPE}-config
COMMENT?=	Configuration manager for ossec-hids-${OSSEC_TYPE}
OSSEC_TYPE?=	local

.include "${.CURDIR}/../ossec-hids/version.mk"

MASTERDIR?=	${.CURDIR}
DISTINFO_FILE?=	${MASTERDIR}/../ossec-hids-local/distinfo

.if ${OSSEC_TYPE} == local
CONFLICTS_INSTALL=	ossec-hids-client-* \
			ossec-hids-agent-* \
			ossec-hids-server-*
.elif ${OSSEC_TYPE} == agent
CONFLICTS_INSTALL=	ossec-hids-client-* \
			ossec-hids-local-* \
			ossec-hids-server-*
.elif ${OSSEC_TYPE} == server
CONFLICTS_INSTALL=	ossec-hids-client-* \
			ossec-hids-agent-* \
			ossec-hids-local-*
.endif

.if !defined(MAINTAINER_MODE)
RUN_DEPENDS=	ossec-hids-${OSSEC_TYPE}>=${PORTVERSION}:security/ossec-hids-${OSSEC_TYPE}
.endif

.if defined(MAINTAINER_MODE)
USE_GITHUB=	yes
GH_ACCOUNT=	ossec
.else
MASTER_SITES=	#
DISTFILES=	#
EXTRACT_ONLY=	#
.endif
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_SUB=			yes

OPTIONS_SINGLE=			FIREWALL
OPTIONS_SINGLE_FIREWALL=	NOFW IPF IPFW PF

OPTIONS_DEFAULT+=		NOFW

FIREWALL_DESC=		Active Response Firewall
PF_DESC=		Packet Filter
IPFW_DESC=		ipfirewall
IPF_DESC=		ipfilter
NOFW_DESC=		Custom or no firewall

TEMPL_ENABLED_HEADER=		template-header-enabled.xml
TEMPL_DISABLED_HEADER=		template-header-disabled.xml
TEMPL_SAMPLE_HEADER=		template-header-sample.xml
TEMPL_PUSHED_ENABLED_HEADER=	${TEMPL_ENABLED_HEADER}
TEMPL_PUSHED_DISABLED_HEADER=	${TEMPL_DISABLED_HEADER}

TEMPL_SAMPLE=		template-sample-${OSSEC_TYPE}.xml
TEMPL_SAMPLE_DB=	template-sample-database.xml

PF_VARS=		FW_DROP=pf.sh PKGMSG_FILES+=message-pf
IPFW_VARS=		FW_DROP=ipfw.sh
IPF_VARS=		FW_DROP=ipfilter.sh
NOFW_VARS=		FW_DROP=

.if defined(MAINTAINER_MODE)
OSSEC_HOME=		${PREFIX}/${PORTNAME}
.else
OSSEC_HOME?=		${PREFIX}/${PORTNAME}
.endif
OSSEC_RC=		${PREFIX}/etc/rc.d/ossec-hids
TEMPL_TO_OSSEC=		${SCRIPTDIR}/template-to-ossec.sh ${OSSEC_TYPE} ${OSSEC_HOME}
TEMPL_TO_AGENT=		${SCRIPTDIR}/template-to-agent.sh ${OSSEC_TYPE} ${OSSEC_HOME}

OSSEC_DIR=		${STAGEDIR}${OSSEC_HOME}
BIN_DIR=		${OSSEC_DIR}/bin
CONF_BIN_DIR=		${BIN_DIR}/config
OSSEC_CONF_BIN=		${CONF_BIN_DIR}/ossec-conf
AGENT_CONF_BIN=		${CONF_BIN_DIR}/agent-conf
COMMAND_BIN_DIR=	${BIN_DIR}/command

AR_BIN_DIR=		${OSSEC_DIR}/active-response/bin
MERGE_CONFIG_BIN=	${AR_BIN_DIR}/merge-config.sh

ETC_DIR=		${OSSEC_DIR}/etc
OSSEC_CONF_DIR=		${ETC_DIR}/ossec.conf.d
AGENT_CONF_DIR=		${ETC_DIR}/agent.conf.d
OSSEC_LOCAL_CONF_DIR=	${OSSEC_CONF_DIR}/disabled
AGENT_LOCAL_CONF_DIR=	${AGENT_CONF_DIR}/disabled
OSSEC_SAMPLE_CONF=	${OSSEC_CONF_DIR}/900.local.conf.sample
COMMAND_CONF_DIR=	${ETC_DIR}
COMMAND_CONF=		${COMMAND_CONF_DIR}/command.conf.sample
RULES_DIR=		${OSSEC_DIR}/rules

.if empty(USER)
USER=$$(${ID} -un)
.endif
.if empty(GROUP)
GROUP=$$(${ID} -gn)
.endif

OSSEC_USER=	ossec
OSSEC_GROUP=	ossec

SUB_LIST+=	PORTNAME=${PORTNAME} \
		OSSEC_TYPE=${OSSEC_TYPE} \
		OSSEC_HOME=${OSSEC_HOME} \
		VERSION=${PORTVERSION} \
		USER=${USER} \
		OSSEC_USER=${OSSEC_USER} \
		OSSEC_GROUP=${OSSEC_GROUP} \
		OSSEC_RC=${OSSEC_RC} \
		FW_DROP=${FW_DROP}
SUB_FILES=	pkg-install \
		pkg-deinstall \
		${PKGMSG_FILES} \
		${TEMPL_ENABLED_HEADER} \
		${TEMPL_DISABLED_HEADER} \
		${TEMPL_SAMPLE_HEADER} \
		${TEMPL_PUSHED_ENABLED_HEADER} \
		${TEMPL_PUSHED_DISABLED_HEADER} \
		${TEMPL_SAMPLE} \
		merge-config.sh \
		ossec-conf \
		command.conf
.if ${OSSEC_TYPE} == server
SUB_FILES+=	agent-conf
.endif

.if defined(MAINTAINER_MODE)
PLIST_SUB=	OSSEC_HOME=${PORTNAME}
.else
PLIST_SUB=	OSSEC_HOME=${OSSEC_HOME}
.endif
PLIST=		${PKGDIR}/pkg-plist-${OSSEC_TYPE}
PKGHELP=	${PKGDIR}/pkg-help-${OSSEC_TYPE}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGMSG_FILES=	message-ossec-conf
.if ${OSSEC_TYPE} == server
PKGMSG_FILES+=	message-agent-conf
.endif

CONF_GROUPS=	RULES AR ROOTCHECK SYSCHECK CMDOUT LOGS

############################################################

.for conf_group in ${CONF_GROUPS}
. include "${MASTERDIR}/opt-${conf_group:tl}.mk"
${conf_group}_INSTANCE_OPTIONS=
${conf_group}_PUSHED_OPTIONS=
. for option in ${${conf_group}_OPTIONS}
.  if ${${option}_DEFINE:M${OSSEC_TYPE}}
${conf_group}_INSTANCE_OPTIONS+=		${option}
${conf_group}_ALL_OPTIONS+=			${option}
.  endif
.  if ${${option}_DEFINE:Mpushed}
.   if ${OSSEC_TYPE} == server
${conf_group}_PUSHED_OPTIONS+=			${option}
.   endif
.   if !${${conf_group}_ALL_OPTIONS:M${option}}
${conf_group}_ALL_OPTIONS+=			${option}
.   endif
.  endif
. endfor
.endfor

############################################################

CONFIG_PROFILES=
.for conf_group in ${CONF_GROUPS}
. if !empty(${conf_group}_PROFILE)
.  if ${OSSEC_TYPE} == agent
.   if !${CONFIG_PROFILES:M${${conf_group}_PROFILE}}
CONFIG_PROFILES+=	${${conf_group}_PROFILE}
.   endif
.  endif
SUB_LIST+=		${conf_group}_PROFILE=${${conf_group}_PROFILE}
. endif
. for option in ${${conf_group}_ALL_OPTIONS}
.  if !empty(${option}_PROFILE)
.   if ${OSSEC_TYPE} == agent
.    if !${CONFIG_PROFILES:M${${option}_PROFILE}}
CONFIG_PROFILES+=	${${option}_PROFILE}
.    endif
.   endif
SUB_LIST+=		${option}_PROFILE=${${option}_PROFILE}
.  endif
. endfor
.endfor

.for profile in ${CONFIG_PROFILES}
. if empty(CONFIG_PROFILE_VALUE)
CONFIG_PROFILE_VALUE:=	${profile}
. else
CONFIG_PROFILE_VALUE:=	${CONFIG_PROFILE_VALUE}, ${profile}
. endif
.endfor
SUB_LIST+=		CONFIG_PROFILES="${CONFIG_PROFILE_VALUE}"

############################################################

.for conf_group in ${CONF_GROUPS}
. for option in ${${conf_group}_ALL_OPTIONS}
.  if !defined(${option}_TEMPLATE)
${option}_TEMPLATE=	template-${option:tl:S/_/-/g}.xml
.  endif
.  if !empty(${option}_TEMPLATE) && !${SUB_FILES:M${${option}_TEMPLATE}}
SUB_FILES+=		${${option}_TEMPLATE}
.  endif
. endfor
.endfor

.for file_name in ${RULES_FILES}
SUB_FILES+=		rules-${file_name}.xml
.endfor

.for file_name in ${CMDOUT_SCRIPTS}
SUB_FILES+=		command-${file_name}.sh
.endfor

############################################################

.for conf_group in ${CONF_GROUPS}
. for option in ${${conf_group}_INSTANCE_OPTIONS}
.  if !empty(${option}_DEPENDS) && !empty(${${option}_DEPENDS}_OPTION) && ${${${option}_DEPENDS:S/_/ /:[1]}_INSTANCE_OPTIONS:M${${option}_DEPENDS}}
${${${option}_DEPENDS}_OPTION}_VARS+=		${conf_group}_INSTANCE_OPTIONS_ENABLED+=${option}
${${${option}_DEPENDS}_OPTION}_VARS_OFF+=	${conf_group}_INSTANCE_OPTIONS_DISABLED+=${option}
.  elif !empty(${option}_OPTION)
OPTIONS_GROUP_G_${conf_group}+=			${${option}_OPTION}
${${option}_OPTION}_DESC=			${${option}_DESC}
.   if ${${option}_DEFAULT:M${OSSEC_TYPE}}
OPTIONS_DEFAULT+=				${${option}_OPTION}
.   endif
${${option}_OPTION}_VARS+=			${conf_group}_INSTANCE_OPTIONS_ENABLED+=${option}
${${option}_OPTION}_VARS_OFF+=			${conf_group}_INSTANCE_OPTIONS_DISABLED+=${option}
.  endif
. endfor
. if !empty(OPTIONS_GROUP_G_${conf_group})
OPTIONS_GROUP+=			G_${conf_group}
G_${conf_group}_DESC=		${${conf_group}_DESC}
. endif
.endfor

############################################################

.for conf_group in ${CONF_GROUPS}
. for option in ${${conf_group}_PUSHED_OPTIONS}
.  if !empty(${option}_DEPENDS) && !empty(${${option}_DEPENDS}_OPTION) && ${${${option}_DEPENDS:S/_/ /:[1]}_PUSHED_OPTIONS:M${${option}_DEPENDS}}
${${${option}_DEPENDS}_OPTION}_P_VARS+=		${conf_group}_PUSHED_OPTIONS_ENABLED+=${option}
${${${option}_DEPENDS}_OPTION}_P_VARS_OFF+=	${conf_group}_PUSHED_OPTIONS_DISABLED+=${option}
.  elif !empty(${option}_DEPENDS) && !empty(${${option}_DEPENDS}_OPTION) && ${${${option}_DEPENDS:S/_/ /:[1]}_INSTANCE_OPTIONS:M${${option}_DEPENDS}}
${${${option}_DEPENDS}_OPTION}_VARS+=		${conf_group}_PUSHED_OPTIONS_ENABLED+=${option}
${${${option}_DEPENDS}_OPTION}_VARS_OFF+=	${conf_group}_PUSHED_OPTIONS_DISABLED+=${option}
.  elif !empty(${option}_OPTION)
OPTIONS_GROUP_G_${conf_group}_P+=		${${option}_OPTION}_P
${${option}_OPTION}_P_DESC=			${${option}_DESC}
.   if !empty(${option}_PROFILE)
${${option}_OPTION}_P_DESC+=			(profile: ${${option}_PROFILE})
.   endif
.   if ${${option}_DEFAULT:Mpushed}
OPTIONS_DEFAULT+=				${${option}_OPTION}_P
.   endif
${${option}_OPTION}_P_VARS+=			${conf_group}_PUSHED_OPTIONS_ENABLED+=${option}
${${option}_OPTION}_P_VARS_OFF+=		${conf_group}_PUSHED_OPTIONS_DISABLED+=${option}
.  endif
. endfor
. if !empty(OPTIONS_GROUP_G_${conf_group}_P)
OPTIONS_GROUP+=			G_${conf_group}_P
G_${conf_group}_P_DESC=		Pushed ${${conf_group}_DESC}
.  if !empty(${conf_group}_PROFILE)
G_${conf_group}_P_DESC+=	(profile: ${${conf_group}_PROFILE})
.  endif
. endif
.endfor

############################################################

.include <bsd.port.pre.mk>

show-opts:
.for conf_group in ${CONF_GROUPS}
	@${ECHO_CMD} "${conf_group}: ${${conf_group}_DESC}"
. for option in ${${conf_group}_INSTANCE_OPTIONS}
	@${ECHO_CMD} "  ${option}: ${${option}_DESC}"
.  if empty(${option}_TEMPLATE)
	@${ECHO_CMD} "    Template: -"
.  else
	@${ECHO_CMD} "    Template: ${${option}_TEMPLATE}"
.  endif
.  if !empty(${conf_group}_INSTANCE_OPTIONS_ENABLED) && ${${conf_group}_INSTANCE_OPTIONS_ENABLED:M${option}}
	@${ECHO_CMD} "    Enabled:  true"
.  endif
.  if !empty(${conf_group}_INSTANCE_OPTIONS_DISABLED) && ${${conf_group}_INSTANCE_OPTIONS_DISABLED:M${option}}
	@${ECHO_CMD} "    Enabled:  false"
.  endif
.  if !empty(${conf_group}_PUSHED_OPTIONS_ENABLED) && ${${conf_group}_PUSHED_OPTIONS_ENABLED:M${option}}
	@${ECHO_CMD} "    Pushed:   true"
.  endif
.  if !empty(${conf_group}_PUSHED_OPTIONS_DISABLED) && ${${conf_group}_PUSHED_OPTIONS_DISABLED:M${option}}
	@${ECHO_CMD} "    Pushed:   false"
.  endif
. endfor
.endfor

pre-install:
	@-${OSSEC_HOME}/bin/ossec-dbd -h 2>&1 | ${GREP} -q 'PostgreSQL' && \
		${SED} -e 's|%%OSSEC_HOME%%|${OSSEC_HOME}|g' -e 's|%%DB_TYPE%%|postgresql|g' \
		${FILESDIR}/${TEMPL_SAMPLE_DB}.in > ${WRKDIR}/${TEMPL_SAMPLE_DB}
	@-${OSSEC_HOME}/bin/ossec-dbd -h 2>&1 | ${GREP} -q 'MySQL' && \
		${SED} -e 's|%%OSSEC_HOME%%|${OSSEC_HOME}|g' -e 's|%%DB_TYPE%%|mysql|g' \
		${FILESDIR}/${TEMPL_SAMPLE_DB}.in > ${WRKDIR}/${TEMPL_SAMPLE_DB}

ossec-dirs:
	@${MKDIR} ${CONF_BIN_DIR} ${COMMAND_BIN_DIR} ${AR_BIN_DIR} ${OSSEC_CONF_DIR} ${OSSEC_LOCAL_CONF_DIR} ${COMMAND_CONF_DIR}
.if ${OSSEC_TYPE} != agent
	@${MKDIR} ${RULES_DIR}
.endif
.if ${OSSEC_TYPE} == server
	@${MKDIR} ${AGENT_CONF_DIR} ${AGENT_LOCAL_CONF_DIR}
.endif

ossec-scripts:
	@${CP} ${WRKDIR}/ossec-conf ${OSSEC_CONF_BIN}
.if ${OSSEC_TYPE} == server
	@${CP} ${WRKDIR}/agent-conf ${AGENT_CONF_BIN}
.endif
.for file_name in ${CMDOUT_SCRIPTS}
	@${CP} ${WRKDIR}/command-${file_name}.sh ${COMMAND_BIN_DIR}/${file_name}.sh
.endfor
	@${CP} ${WRKDIR}/command.conf ${COMMAND_CONF}
	@${CP} ${WRKDIR}/merge-config.sh ${MERGE_CONFIG_BIN}

ossec-rules:
.if ${OSSEC_TYPE} != agent
. for file_name in ${RULES_FILES}
	@${SED} -e 's|<?xml.*?>||' ${WRKDIR}/rules-${file_name}.xml > ${RULES_DIR}/freebsd_${file_name}_rules.xml
. endfor
.endif

ossec-conf-managed:
.for conf_group in ${CONF_GROUPS}
. if !empty(${conf_group}_INSTANCE_OPTIONS)
	@${CAT} ${WRKDIR}/${TEMPL_ENABLED_HEADER} > ${OSSEC_CONF_DIR}/${${conf_group}_MANAGED_CONF}
.  if !empty(${conf_group}_INSTANCE_OPTIONS_ENABLED)
.   for option in ${${conf_group}_INSTANCE_OPTIONS}
.    if ${${conf_group}_INSTANCE_OPTIONS_ENABLED:M${option}}
.     if !empty(${option}_TEMPLATE)
	@${ECHO_CMD} "<!-- Enabled ${${option}_OPTION} -->" >> ${OSSEC_CONF_DIR}/${${conf_group}_MANAGED_CONF}
	@${SH} ${TEMPL_TO_OSSEC} ${WRKDIR}/${${option}_TEMPLATE} >> ${OSSEC_CONF_DIR}/${${conf_group}_MANAGED_CONF}
	@${ECHO_CMD} >> ${OSSEC_CONF_DIR}/${${conf_group}_MANAGED_CONF}
.     endif
.    endif
.   endfor
.  endif
. endif
.endfor

ossec-conf-local:
.for conf_group in ${CONF_GROUPS}
. if !empty(${conf_group}_INSTANCE_OPTIONS)
	@${CAT} ${WRKDIR}/${TEMPL_DISABLED_HEADER} > ${OSSEC_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
.  if !empty(${conf_group}_INSTANCE_OPTIONS_DISABLED)
.   for option in ${${conf_group}_INSTANCE_OPTIONS}
.    if ${${conf_group}_INSTANCE_OPTIONS_DISABLED:M${option}}
.     if !empty(${option}_TEMPLATE)
	@${ECHO_CMD} "<!-- Disabled ${${option}_OPTION} -->" >> ${OSSEC_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
	@${SH} ${TEMPL_TO_OSSEC} ${WRKDIR}/${${option}_TEMPLATE} >> ${OSSEC_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
	@${ECHO_CMD} >> ${OSSEC_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
.     endif
.    endif
.   endfor
.  endif
. endif
.endfor

ossec-conf-sample:
	@${CAT} ${WRKDIR}/${TEMPL_SAMPLE_HEADER} > ${OSSEC_SAMPLE_CONF}
	@${ECHO_CMD} >> ${OSSEC_SAMPLE_CONF}
	@${SH} ${TEMPL_TO_OSSEC} ${WRKDIR}/${TEMPL_SAMPLE} >> ${OSSEC_SAMPLE_CONF}
	@${ECHO_CMD} >> ${OSSEC_SAMPLE_CONF}
	@-${TEST} -f ${WRKDIR}/${TEMPL_SAMPLE_DB} && \
		${SH} ${TEMPL_TO_OSSEC} ${WRKDIR}/${TEMPL_SAMPLE_DB} >> ${OSSEC_SAMPLE_CONF} && \
		${ECHO_CMD} >> ${OSSEC_SAMPLE_CONF}

agent-conf-managed:
.for conf_group in ${CONF_GROUPS}
. if !empty(${conf_group}_PUSHED_OPTIONS)
	@${CAT} ${WRKDIR}/${TEMPL_PUSHED_ENABLED_HEADER} > ${AGENT_CONF_DIR}/${${conf_group}_MANAGED_CONF}
.  if !empty(${conf_group}_PUSHED_OPTIONS_ENABLED)
.   for option in ${${conf_group}_PUSHED_OPTIONS}
.    if ${${conf_group}_PUSHED_OPTIONS_ENABLED:M${option}}
.     if !empty(${option}_TEMPLATE)
	@${ECHO_CMD} "<!-- Enabled ${${option}_OPTION}_P -->" >> ${AGENT_CONF_DIR}/${${conf_group}_MANAGED_CONF}
	@${SH} ${TEMPL_TO_AGENT} ${WRKDIR}/${${option}_TEMPLATE} >> ${AGENT_CONF_DIR}/${${conf_group}_MANAGED_CONF}
	@${ECHO_CMD} >> ${AGENT_CONF_DIR}/${${conf_group}_MANAGED_CONF}
.     endif
.    endif
.   endfor
.  endif
. endif
.endfor

agent-conf-local:
.for conf_group in ${CONF_GROUPS}
. if !empty(${conf_group}_PUSHED_OPTIONS)
	@${CAT} ${WRKDIR}/${TEMPL_PUSHED_DISABLED_HEADER} > ${AGENT_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
.  if !empty(${conf_group}_PUSHED_OPTIONS_DISABLED)
.   for option in ${${conf_group}_PUSHED_OPTIONS}
.    if ${${conf_group}_PUSHED_OPTIONS_DISABLED:M${option}}
.     if !empty(${option}_TEMPLATE)
	@${ECHO_CMD} "<!-- Disabled ${${option}_OPTION}_P -->" >> ${AGENT_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
	@${SH} ${TEMPL_TO_AGENT} ${WRKDIR}/${${option}_TEMPLATE} >> ${AGENT_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
	@${ECHO_CMD} >> ${AGENT_LOCAL_CONF_DIR}/${${conf_group}_LOCAL_CONF}
.     endif
.    endif
.   endfor
.  endif
. endif
.endfor

do-install: ossec-dirs ossec-scripts ossec-rules ossec-conf-managed ossec-conf-local ossec-conf-sample agent-conf-managed agent-conf-local

ossec-permissions:
.if defined(MAINTAINER_MODE)
	@${CHMOD} -R 550 ${OSSEC_DIR}
	@${CHMOD} 640 ${COMMAND_CONF} ${OSSEC_LOCAL_CONF_DIR}/* ${OSSEC_CONF_DIR}/*
	@${CHMOD} 550 ${OSSEC_LOCAL_CONF_DIR} ${OSSEC_CONF_DIR}
. if ${OSSEC_TYPE} != agent
	@${CHMOD} 640 ${RULES_DIR}/*
. endif
. if ${OSSEC_TYPE} == server
	@${CHMOD} 640 ${AGENT_LOCAL_CONF_DIR}/* ${AGENT_CONF_DIR}/*
	@${CHMOD} 550 ${AGENT_LOCAL_CONF_DIR} ${AGENT_CONF_DIR}
. endif
	@${CHOWN} -R ${USER}:${OSSEC_GROUP} ${OSSEC_DIR}
	@${CHOWN} -R ${USER}:${GROUP} ${BIN_DIR}
.endif

post-install: ossec-permissions
	@${ECHO_CMD} -n > ${PKGMESSAGE}
.for file_name in ${PKGMSG_FILES}
	@${CAT} ${WRKDIR}/${file_name} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
.endfor

.if defined(MAINTAINER_MODE)
plist: makeplist
	@${SH} ${SCRIPTDIR}/plist.sh ${OSSEC_TYPE} ${OSSEC_HOME} ${PLIST} ${WRKDIR} ${STAGEDIR}

rules: extract
	@${SH} ${SCRIPTDIR}/rules.sh ${FILESDIR}/${RULES_DEFAULT_TEMPLATE}.in ${WRKSRC}
.endif

.include <bsd.port.post.mk>

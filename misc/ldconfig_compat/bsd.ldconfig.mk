LDCONFIG_DIR=	libdata/ldconfig
LDCONFIG32_DIR=	libdata/ldconfig32

.if defined(USE_LDCONFIG) || defined(USE_LDCONFIG32)
.if ${OSVERSION} < 504105 || \
 	( ${OSVERSION} >= 700000 && ${OSVERSION} < 700012 ) || \
	( ${OSVERSION} >= 600000 && ${OSVERSION} < 600104 )
RUN_DEPENDS+=	${LOCALBASE}/${LDCONFIG_DIR}:${PORTSDIR}/misc/ldconfig_compat
.endif
.endif

.if !target(install-ldconfig-file)
install-ldconfig-file:
.if defined(USE_LDCONFIG) || defined(USE_LDCONFIG32)
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
.if defined(USE_LDCONFIG)
	@${ECHO_MSG} "===>   Installing ldconfig configuration file"
	@${MKDIR} ${PREFIX}/${LDCONFIG_DIR}
	@${ECHO_CMD} ${USE_LDCONFIG} | ${TR} ' ' '\n' \
		> ${PREFIX}/${LDCONFIG_DIR}/${UNIQUENAME}
	@${ECHO_CMD} ${LDCONFIG_DIR}/${UNIQUENAME} >> ${TMPPLIST}
.endif
.if defined(USE_LDCONFIG32)
	@${ECHO_MSG} "===>   Installing 32-bit ldconfig configuration file"
	@${MKDIR} ${PREFIX}/${LDCONFIG32_DIR}
	@${ECHO_CMD} ${USE_LDCONFIG32} | ${TR} ' ' '\n' \
		> ${PREFIX}/${LDCONFIG32_DIR}/${UNIQUENAME}
	@${ECHO_CMD} ${LDCONFIG32_DIR}/${UNIQUENAME} >> ${TMPPLIST}
.endif
.else
	@${DO_NADA}
.endif
.endif

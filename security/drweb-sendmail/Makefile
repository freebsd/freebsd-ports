# New ports collection makefile for:   drweb_sendmail
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb_sendmail
PORTVERSION=    4.29
CATEGORIES=	security mail
MASTER_SITES=   ftp://ftp.drweb.ru/pub/unix/
DISTNAME=       drweb-clients-${PORTVERSION}-sources

MAINTAINER=	anton@chelcom.ru

RUN_DEPENDS=    ${LOCALBASE}/etc/rc.d/drweb-0.sh:${PORTSDIR}/security/drwebd

WRKSRC=         ${WRKDIR}/${DISTNAME}

INST_PREFIX=	${PREFIX}/${PORTNAME}
DOC_DIR=	${PREFIX}/share/doc/drweb-sendmail

.if !exists( /usr/include/libmilter/mfapi.h )
BUILD_DEPENDS+=	${LOCALBASE}/include/libmilter/mfapi.h:${PORTSDIR}/mail/sendmail
.endif

.if !defined(WITH_DRWEBSMF_HOSTNAME)
.if defined(BATCH)
WITH_DRWEBSMF_HOSTNAME= your.domain.name
.else
WITH_DRWEBSMF_HOSTNAME!=hostname
.endif
.endif

.if defined(BATCH)
RANDOM_NUMBER=!!!___EDIT_THIS___!!!
.else
RANDOM_NUMBER!=dd if=/dev/random count=1 2> /dev/null | /sbin/md5
.endif

LANGS=en-ru en-es
CONFS=drweb_smf users
TMPLS=error-admin error-sender mailbomb-admin mailbomb-sender skip-sender \
      virus-admin virus-rcpts virus-sender

post-patch:
	${SED} "s#%PREFIX%#${PREFIX}#g" < ${FILESDIR}/drweb-sendmail.sh \
	    > ${WRKSRC}/drweb-sendmail.sh
	cd ${WRKSRC} && \
	${SED} "s#%PREFIX%#${PREFIX}#g" < dw_options.c > ndwo.c && \
	    mv ndwo.c dw_options.c
	cd ${WRKSRC}/etc && \
	${SED} "s#%PREFIX%#${PREFIX}#g;\
		s#%HOSTNAME%#${WITH_DRWEBSMF_HOSTNAME}#g;\
		s#!!!___EDIT_THIS___!!!#${RANDOM_NUMBER}#" \
	    < drweb_smf.conf > ndrwsmf.conf && \
	    mv ndrwsmf.conf drweb_smf.conf

post-configure:
	cd ${WRKSRC} && { \
		${ECHO_CMD} y; \
		${ECHO_CMD} n; \
		${ECHO_CMD} y; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} y; \
		${ECHO_CMD} n; \
		${ECHO_CMD} ${CFLAGS} ; \
		${ECHO_CMD} y; \
	} | ./configure

do-install:
	${MKDIR} ${DOC_DIR}
.for LANG in ${LANGS}
	${MKDIR} ${PREFIX}/etc/drweb/templates/${LANG}/sendmail
.endfor
.for CONF in ${CONFS}
	${INSTALL_DATA} -m 600 ${WRKSRC}/etc/${CONF}.conf \
	    ${PREFIX}/etc/drweb/${CONF}.conf-dist
	if [ ! -f ${PREFIX}/etc/drweb/${CONF}.conf ]; then \
	    ${INSTALL_DATA} -m 600 ${WRKSRC}/etc/${CONF}.conf \
		${PREFIX}/etc/drweb/${CONF}.conf; \
	fi
.endfor
.for LANG in ${LANGS}
.for TMPL in ${TMPLS}
	cd ${WRKSRC}/etc/templates/${LANG}/sendmail && \
	    ${INSTALL_DATA} ${TMPL}.msg \
		${PREFIX}/etc/drweb/templates/${LANG}/sendmail/${TMPL}.msg-dist
	if [ ! -f ${PREFIX}/etc/drweb/templates/${LANG}/sendmail/${TMPL}.msg ]; then \
		cd ${PREFIX}/etc/drweb/templates/${LANG}/sendmail && \
		${CP} ${TMPL}.msg-dist ${TMPL}.msg; \
	fi
.endfor
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/drweb-smf ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/drwebdc ${PREFIX}/sbin/
	cd ${WRKSRC}/doc/sendmail && { \
		${ECHO_CMD} ; \
		${ECHO_CMD} "${PREFIX}/drweb"; \
		${ECHO_CMD} "${PREFIX}/drweb/drweb32.ini"; \
		${ECHO_CMD} "${PREFIX}/sbin"; \
		${ECHO_CMD} "${PREFIX}/etc/drweb/drweb_smf.conf"; \
		${ECHO_CMD} ; \
		${ECHO_CMD} ; \
		${ECHO_CMD} t; \
		${ECHO_CMD} ; \
		${ECHO_CMD} ; \
	} | ./configure
	cd ${WRKSRC}/doc/sendmail && \
		${INSTALL_DATA} readme* *.txt sendmail.??.addon \
		${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/drweb-sendmail.sh \
	    ${PREFIX}/etc/rc.d/drweb-sendmail.sh-dist
	if [ ! -f ${PREFIX}/etc/rc.d/drweb-sendmail.sh ]; then \
		${INSTALL_SCRIPT} ${WRKSRC}/drweb-sendmail.sh \
		    ${PREFIX}/etc/rc.d/; \
	fi

post-install:
	@echo
	@echo "Read documentation about additional sendmail tuning needed"
	@echo "in ${DOC_DIR}."
	@echo

.include <bsd.port.mk>

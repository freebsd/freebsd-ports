# New ports collection makefile for:   drweb_postfix
# Date created:        5 December 2002
# Whom:                zhuravlev alexander <zaa@ulstu.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb_postfix
PORTVERSION=	4.29
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/
DISTNAME=	drweb-clients-${PORTVERSION}-sources

MAINTAINER=	zaa@ulstu.ru

RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/drweb-0.sh:${PORTSDIR}/security/drwebd

WRKSRC=		${WRKDIR}/${DISTNAME}

INST_PREFIX=	${PREFIX}/${PORTNAME}
DOC_DIR=	${PREFIX}/share/doc/drweb-postfix

LANGS=en-ru en-es
CONFS=drweb_postfix users
TMPLS=error-admin error-sender mailbomb-admin mailbomb-sender skip-sender \
      virus-admin virus-rcpts virus-sender
DOCS=readme notify.rus.txt users_list.rus.txt conf_file.rus.txt notify.txt \
	users_list.txt conf_file.txt readme.rus

post-patch:
	cd ${WRKSRC} && \
	${SED} "s#%PREFIX%#${PREFIX}#g" < dw_options.c > ndwo.c && \
		${MV} ndwo.c dw_options.c
	cd ${WRKSRC}/etc && \
	${SED} -e "s#%PREFIX%#${PREFIX}#g" -e "s#%HOSTNAME%#${HOST}#g" \
		< drweb_postfix.conf > nconf && \
		${MV} nconf drweb_postfix.conf

post-configure:
	cd ${WRKSRC} && { \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} y; \
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
	${MKDIR} ${PREFIX}/etc/drweb/templates/${LANG}/postfix
.endfor
.for CONF in ${CONFS}
	${INSTALL_DATA} -m 640 -o drweb -g drweb ${WRKSRC}/etc/${CONF}.conf \
	    ${PREFIX}/etc/drweb/${CONF}.conf-dist
	if [ ! -f ${PREFIX}/etc/drweb/${CONF}.conf ]; then \
	   ${INSTALL_DATA} -m 640 -o drweb -g drweb ${WRKSRC}/etc/${CONF}.conf \
		${PREFIX}/etc/drweb/${CONF}.conf; \
	fi
.endfor
.for LANG in ${LANGS}
.for TMPL in ${TMPLS}
	cd ${WRKSRC}/etc/templates/${LANG}/postfix && \
	    ${INSTALL_DATA} ${TMPL}.msg \
		${PREFIX}/etc/drweb/templates/${LANG}/postfix/${TMPL}.msg-dist
	if [ ! -f ${PREFIX}/etc/drweb/templates/${LANG}/postfix/${TMPL}.msg ]; then \
		cd ${PREFIX}/etc/drweb/templates/${LANG}/postfix && \
		${CP} ${TMPL}.msg-dist ${TMPL}.msg; \
	fi
.endfor
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/drweb-postfix ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/drwebdc ${PREFIX}/sbin/
	cd ${WRKSRC}/doc/postfix && \
		${INSTALL_DATA} ${DOCS} ${DOC_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}
	@echo
	@echo "Read documentation about additional Postfix tuning needed"
	@echo "in ${DOC_DIR}."
	@echo

.include <bsd.port.mk>

# New ports collection makefile for:   drweb_postfix
# Date created:        5 December 2002
# Whom:                zhuravlev alexander <zaa@ulstu.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb_postfix
PORTVERSION=	4.31
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/ \
		ftp://ftp.drweb.ru/pub/unix/archive/ \
		ftp://ftp.drweb.ru/pub/unix/archive/drweb-clients-${PORTVERSION}/
DISTNAME=	drweb-clients-${PORTVERSION}-sources

MAINTAINER=	zaa@ulstu.ru
COMMENT=	Postfix message filter for virus processing through DrWeb daemon

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2
RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

WRKSRC=		${WRKDIR}/${DISTNAME}

INST_PREFIX=	${PREFIX}/${PORTNAME}

LANGS=en-ru
CONFS=drweb_postfix users viruses addresses
TMPLS=archive-admin archive-sender error-admin error-sender skip-sender \
      virus-admin virus-rcpts virus-sender rule-admin
PORTDOCS=	FAQ.rus.txt addresses_list.rus.txt addresses_list.txt conf_file.rus.txt \
	conf_file.txt notify.rus.txt notify.txt readme readme.rus \
	users_list.rus.txt users_list.txt viruses_list.rus.txt viruses_list.txt

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
		${ECHO_CMD} ${PORTVERSION}; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} y; \
		${ECHO_CMD} n; \
		${ECHO_CMD} n; \
		${ECHO_CMD} y; \
		${ECHO_CMD} ${CFLAGS} ; \
		${ECHO_CMD} y; \
	} | ./configure

do-install:
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/postfix && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} "Read documentation about additional Postfix tuning needed"
	@${ECHO} "in ${DOCSDIR}."
	@${ECHO}

.include <bsd.port.mk>

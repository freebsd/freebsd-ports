# New ports collection makefile for:	drweb-qmail
# Date created:				5 February 2003
# Whom:					Denis N. Peplin <info@volginfo.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb-qmail
PORTVERSION=	4.32.1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/FreeBSD/49/ \
		ftp://ftp.drweb.ru/pub/unix/FreeBSD/53/

MAINTAINER=	support@spectrum.ru
COMMENT=	Qmail client for DrWeb antivirus suite

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd49
.else
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd53
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
INST_PREFIX=	${PREFIX}/${PORTNAME}
DOC_DIR=	${PREFIX}/share/doc/${PORTNAME}
CONFDIR=	${PREFIX}/etc/${PORTNAME}

LANGS=		en en-ru en-pl en-jp
CONFS=		drweb_qmail users viruses addresses
TMPLS=		archive-admin archive-sender cured-admin cured-sender error-admin \
		error-sender rule-admin skip-sender virus-admin virus-rcpts \
		virus-sender license-admin

do-install:
	${MKDIR} ${INST_PREFIX}
	${MKDIR} ${INST_PREFIX}/run
	${CHOWN} drweb:drweb ${INST_PREFIX}/run
	${MKDIR} ${CONFDIR}
	${MKDIR} ${DOC_DIR}
	${MKDIR} ${DOC_DIR}/qmail
	${INSTALL_PROGRAM} ${WRKSRC}/usr/local/drweb/qmail-queue.static \
	${INST_PREFIX}/qmail-queue.drweb
	${SED} 's#%INSTALL%#${INST_PREFIX}#g' \
		< ${FILESDIR}/01.drweb-qmail.sh \
		> ${PREFIX}/etc/rc.d/01.drweb-qmail.sh-dist
	${CHMOD} 750 ${PREFIX}/etc/rc.d/01.drweb-qmail.sh-dist
.for LANG in ${LANGS}
		${MKDIR} ${PREFIX}/etc/${PORTNAME}/templates/${LANG}/qmail
.endfor
.for CONF in ${CONFS}
		${SED} 's#%CONFDIR%#${CONFDIR}#g' \
			< ${WRKSRC}/usr/local/etc/drweb/${CONF}.conf \
			> ${CONFDIR}/${CONF}.conf-dist
		${CHMOD} 640 ${CONFDIR}/${CONF}.conf-dist
.if !exists( ${PREFIX}/etc/${PORTNAME}/${CONF}.conf )
			${CP} ${CONFDIR}/${CONF}.conf-dist ${CONFDIR}/${CONF}.conf
			${CHMOD} 600 ${CONFDIR}/${CONF}.conf
.endif
.endfor
.for LANG in ${LANGS}
.for TMPL in ${TMPLS}
			${INSTALL_DATA} ${WRKSRC}/usr/local/etc/drweb/templates/${LANG}/qmail/${TMPL}.msg \
			${PREFIX}/etc/${PORTNAME}/templates/${LANG}/qmail/${TMPL}.msg-dist
.if !exists( ${PREFIX}/etc/${PORTNAME}/templates/${LANG}/qmail/${TMPL}.msg )
				${INSTALL_DATA} -o drweb -g drweb -m 640 ${WRKSRC}/usr/local/etc/drweb/templates/${LANG}/qmail/${TMPL}.msg \
				${PREFIX}/etc/${PORTNAME}/templates/${LANG}/qmail/${TMPL}.msg
.endif
.endfor
.endfor
	${CP} ${WRKSRC}/usr/local/drweb/doc/qmail/*.txt \
	${DOC_DIR}/qmail/
	${CP} ${WRKSRC}/usr/local/drweb/doc/qmail/read* \
	${DOC_DIR}/qmail/

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} "Read documentation about additional QMail tuning needed"
	@${ECHO} "in ${DOCSDIR}."
	@${ECHO}

.include <bsd.port.post.mk>

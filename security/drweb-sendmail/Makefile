# New ports collection makefile for:   drweb_sendmail
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb-sendmail
PORTVERSION=	4.32.1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/FreeBSD/49/ \
		ftp://ftp.drweb.ru/pub/unix/FreeBSD/53/

MAINTAINER=     support@spectrum.ru
COMMENT=        Sendmail message filter for virus processing through DrWeb daemon

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb \
		/usr/include/libmilter/mfapi.h:${PORTSDIR}/mail/sendmail

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
DISTNAME=       ${PORTNAME}-${PORTVERSION}-freebsd49
.else
DISTNAME=       ${PORTNAME}-${PORTVERSION}-freebsd53
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
INST_PREFIX=    ${PREFIX}/${PORTNAME}
DOC_DIR=        ${PREFIX}/share/doc/${PORTNAME}
CONFDIR=	${PREFIX}/etc/${PORTNAME}

LANGS=	en en-ru en-pl en-jp
CONFS=	drweb_smf users viruses addresses
TMPLS=	archive-admin archive-sender cured-admin cured-sender error-admin \
	error-sender rule-admin skip-sender virus-admin virus-rcpts virus-sender \
	license-admin

do-install:
	${MKDIR} ${INST_PREFIX}
	${MKDIR} ${INST_PREFIX}/run
	${CHOWN} drweb:drweb ${INST_PREFIX}/run
	${MKDIR} ${CONFDIR}
	${MKDIR} ${DOC_DIR}
	${MKDIR} ${DOC_DIR}/sendmail
	${INSTALL_PROGRAM} ${WRKSRC}/usr/local/drweb/drweb-smf.static \
		${INST_PREFIX}/drweb-smf
	${SED} 's#%INSTALL%#${INST_PREFIX}#g' \
		< ${FILESDIR}/01.drweb-smf.sh \
		> ${PREFIX}/etc/rc.d/01.drweb-smf.sh-dist
	${CHMOD} 750 ${PREFIX}/etc/rc.d/01.drweb-smf.sh-dist
.for LANG in ${LANGS}
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/templates/${LANG}/sendmail
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
	${INSTALL_DATA} ${WRKSRC}/usr/local/etc/drweb/templates/${LANG}/sendmail/${TMPL}.msg \
		${PREFIX}/etc/${PORTNAME}/templates/${LANG}/sendmail/${TMPL}.msg-dist
.if !exists( ${PREFIX}/etc/${PORTNAME}/templates/${LANG}/sendmail/${TMPL}.msg )
	${INSTALL_DATA} -o drweb -g drweb -m 640 ${WRKSRC}/usr/local/etc/drweb/templates/${LANG}/sendmail/${TMPL}.msg \
		${PREFIX}/etc/${PORTNAME}/templates/${LANG}/sendmail/${TMPL}.msg
.endif
.endfor
.endfor
	${CP} ${WRKSRC}/usr/local/drweb/doc/sendmail/*.txt \
		${DOC_DIR}/sendmail/
	${CP} ${WRKSRC}/usr/local/drweb/doc/sendmail/read* \
                ${DOC_DIR}/sendmail/

.include <bsd.port.post.mk>

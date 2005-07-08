# New ports collection makefile for:   drweb_postfix
# Date created:        5 December 2002
# Whom:                zhuravlev alexander <zaa@ulstu.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb-postfix
PORTVERSION=	4.32.1
PORTREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/FreeBSD/49/ \
		ftp://ftp.drweb.ru/pub/unix/FreeBSD/53/

MAINTAINER=	support@spectrum.ru
COMMENT=	Postfix message filter for virus processing through DrWeb daemon

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
CONFS=		drweb_postfix users viruses addresses
TMPLS=		archive-admin archive-sender cured-admin cured-sender error-admin \
		error-sender rule-admin skip-sender virus-admin virus-rcpts \
		virus-sender license-admin

do-install:
	${MKDIR} ${INST_PREFIX}
	${MKDIR} ${INST_PREFIX}/run
	${CHOWN} drweb:drweb ${INST_PREFIX}/run
	${MKDIR} ${CONFDIR}
	${MKDIR} ${DOC_DIR}
	${MKDIR} ${DOC_DIR}/postfix
	${INSTALL_PROGRAM} ${WRKSRC}/usr/local/drweb/drweb-postfix.static \
		${INST_PREFIX}/drweb-postfix
	${SED} 's#%INSTALL%#${INST_PREFIX}#g' \
		< ${FILESDIR}/01.drweb-postfix.sh \
		> ${PREFIX}/etc/rc.d/01.drweb-postfix.sh-dist
	${CHMOD} 750 ${PREFIX}/etc/rc.d/01.drweb-postfix.sh-dist
.for LANG in ${LANGS}
	${MKDIR} ${PREFIX}/etc/${PORTNAME}/templates/${LANG}/postfix
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
	${INSTALL_DATA} ${WRKSRC}/usr/local/etc/drweb/templates/${LANG}/postfix/${TMPL}.msg \
		${PREFIX}/etc/${PORTNAME}/templates/${LANG}/postfix/${TMPL}.msg-dist
.if !exists( ${PREFIX}/etc/${PORTNAME}/templates/${LANG}/postfix/${TMPL}.msg )
	${INSTALL_DATA} -o drweb -g drweb -m 640 ${WRKSRC}/usr/local/etc/drweb/templates/${LANG}/postfix/${TMPL}.msg \
		${PREFIX}/etc/${PORTNAME}/templates/${LANG}/postfix/${TMPL}.msg
.endif
.endfor
.endfor
	${CP} ${WRKSRC}/usr/local/drweb/doc/postfix/*.txt \
		${DOC_DIR}/postfix/
	${CP} ${WRKSRC}/usr/local/drweb/doc/postfix/read* \
		${DOC_DIR}/postfix/

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} "Read documentation about additional Postfix tuning needed"
	@${ECHO} "in ${DOCSDIR}."
	@${ECHO}

.include <bsd.port.post.mk>

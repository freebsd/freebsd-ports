# New ports collection makefile for:	drweb-qmail
# Date created:				5 February 2003
# Whom:					Denis N. Peplin <info@volginfo.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb-qmail
PORTVERSION=	4.44.1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/60/ \
		http://freebsd.spectrum.ru/distfiles/drweb/
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd60
DIST_SUBDIR=	drweb

MAINTAINER=	support@spectrum.ru
COMMENT=	Qmail message filter for virus processing through DrWeb daemon

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

IA32_BINARY_PORT=	yes
NO_BUILD=		yes
USE_BZIP2=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
IGNORE=		sorry, port is not supported of FreeBSD version < 6.1
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
INST_PREFIX=	${PREFIX}/drweb
CONF_PREFIX=	${PREFIX}/etc/drweb

LANGS=		en en-pl en-ru
CONFS=		addresses drweb_qmail users viruses
TMPLS=		admin_archive admin_cured admin_error admin_license admin_malware \
		admin_rule admin_virus rcpts_malware rcpts_virus sender_archive \
		sender_cured sender_error sender_malware sender_skip sender_virus

do-install:
	${INSTALL_PROGRAM} -m 0750 -o drweb -g drweb \
		${WRKSRC}${LOCALBASE}/drweb/qmail-queue.static ${INST_PREFIX}/drweb-qmail
.for CONF in ${CONFS}
	${SED} -e s#/usr/local/drweb/run#/var/drweb/run#g \
		< ${WRKSRC}${LOCALBASE}/etc/drweb/${CONF}.conf > \
		${CONF_PREFIX}/${CONF}.conf-distr
.if !exists( ${CONF_PREFIX}/${CONF}.conf )
	${CP} ${CONF_PREFIX}/${CONF}.conf-distr ${CONF_PREFIX}/${CONF}.conf
.endif
.endfor
.for LANG in ${LANGS}
	${MKDIR} ${CONF_PREFIX}/templates/${LANG}/qmail
.endfor
.for LANG in ${LANGS}
.for TMPL in ${TMPLS}
	${INSTALL} -m 0640 -o drweb -g drweb ${WRKSRC}${LOCALBASE}/etc/drweb/templates/${LANG}/${TMPL}.msg \
		${CONF_PREFIX}/templates/${LANG}/qmail/${TMPL}.msg-distr
.if !exists( ${CONF_PREFIX}/templates/${LANG}/qmail/${TMPL}.msg )
	${CP} ${CONF_PREFIX}/templates/${LANG}/qmail/${TMPL}.msg-distr \
		${CONF_PREFIX}/templates/${LANG}/qmail/${TMPL}.msg
.endif
.endfor
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -cf - -C ${WRKSRC}${LOCALBASE}/drweb/doc/qmail . | \
		${TAR} -xf - -C ${DOCSDIR}
.endif
	@${ECHO}
	@${ECHO} "Read documentation about additional Qmail tuning needed"
	@${ECHO} "in ${DOCSDIR}."
	@${ECHO}

.include <bsd.port.post.mk>

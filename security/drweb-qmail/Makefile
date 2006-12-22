# New ports collection makefile for:	drweb-qmail
# Date created:				5 February 2003
# Whom:					Denis N. Peplin <info@volginfo.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb-qmail
PORTVERSION=	4.33
PORTREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/61/:f61 \
		ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/55/:f55 \
		ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/411/:f411 \
		http://freebsd.spectrum.ru/distfiles/drweb/:f61,f55,f411
DIST_SUBDIR=	drweb

MAINTAINER=	support@spectrum.ru
COMMENT=	Qmail message filter for virus processing through DrWeb daemon

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

IA32_BINARY_PORT=	yes
NO_BUILD=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd411
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:f411
.elif ${OSVERSION} >= 601000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd61
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:f61
.else
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd55
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:f55
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
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

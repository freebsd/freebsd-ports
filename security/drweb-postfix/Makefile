# New ports collection makefile for:   drweb_postfix
# Date created:        5 December 2002
# Whom:                zhuravlev alexander <zaa@ulstu.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb-postfix
PORTVERSION=	4.44.1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/60/ \
		http://freebsd.spectrum.ru/distfiles/drweb/
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd60
DIST_SUBDIR=	drweb

MAINTAINER=	support@spectrum.ru
COMMENT=	Postfix message filter for virus processing through DrWeb daemon

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

IA32_BINARY_PORT=	yes
NO_BUILD=		yes
USE_BZIP2=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
IGNORE=	sorry, port is not supported of FreeBSD version < 6.1
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
INST_PREFIX=	${PREFIX}/drweb
CONF_PREFIX=	${PREFIX}/etc/drweb

LANGS=		en en-pl en-ru
CONFS=		addresses drweb_postfix users viruses
TMPLS=		admin_archive admin_cured admin_error admin_license admin_malware \
		admin_rule admin_virus rcpts_malware rcpts_virus sender_archive \
		sender_cured sender_error sender_malware sender_skip sender_virus

do-install:
	${INSTALL_PROGRAM} -m 0750 -o drweb -g drweb \
		${WRKSRC}${LOCALBASE}/drweb/drweb-postfix.static ${INST_PREFIX}/drweb-postfix
.for CONF in ${CONFS}
	${INSTALL_DATA} -m 0640 -o drweb -g drweb \
		${WRKSRC}${LOCALBASE}/etc/drweb/${CONF}.conf \
		${CONF_PREFIX}/${CONF}.conf-distr
.if !exists( ${CONF_PREFIX}/${CONF}.conf )
	${CP} ${CONF_PREFIX}/${CONF}.conf-distr ${CONF_PREFIX}/${CONF}.conf
.endif
.endfor
.for LANG in ${LANGS}
	${MKDIR} ${CONF_PREFIX}/templates/${LANG}/postfix
.endfor
.for LANG in ${LANGS}
.for TMPL in ${TMPLS}
	${INSTALL} -m 0640 -o drweb -g drweb ${WRKSRC}${LOCALBASE}/etc/drweb/templates/${LANG}/${TMPL}.msg \
		${CONF_PREFIX}/templates/${LANG}/postfix/${TMPL}.msg-distr
.if !exists( ${CONF_PREFIX}/templates/${LANG}/postfix/${TMPL}.msg )
	${CP} ${CONF_PREFIX}/templates/${LANG}/postfix/${TMPL}.msg-distr \
		${CONF_PREFIX}/templates/${LANG}/postfix/${TMPL}.msg
.endif
.endfor
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -cf - -C ${WRKSRC}/usr/local/drweb/doc/postfix . | \
		${TAR} -xf - -C ${DOCSDIR} --exclude "configure*"
.endif
	@${ECHO}
	@${ECHO} "Read documentation about additional Postfix tuning needed"
	@${ECHO} "in ${DOCSDIR}."
	@${ECHO}

.include <bsd.port.post.mk>

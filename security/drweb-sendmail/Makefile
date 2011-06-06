# New ports collection makefile for:   drweb_sendmail
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb-sendmail
PORTVERSION=	4.44.1
PORTREVISION=	1
CATEGORIES=	security mail
MASTER_SITES=	ftp://ftp.drweb.com/pub/drweb/unix/FreeBSD/70/ \
		http://freebsd.spectrum.ru/distfiles/drweb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sendmail message filter for virus processing through DrWeb daemon

DEPRECATED=		fails to fetch (website rearranged)
EXPIRATION_DATE=	2011-08-06

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

IA32_BINARY_PORT=	yes
NO_BUILD=		yes
USE_RC_SUBR=		drweb-smf
USE_BZIP2=		yes

.include <bsd.port.pre.mk>

DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd70
DIST_SUBDIR=	drweb

WRKSRC=		${WRKDIR}/${DISTNAME}
INST_PREFIX=	${PREFIX}/drweb
CONF_PREFIX=	${PREFIX}/etc/drweb

LANGS=		en en-pl en-ru
CONFS=		addresses drweb_smf users viruses
TMPLS=		admin_archive admin_cured admin_error admin_license admin_malware \
		admin_rule admin_virus rcpts_malware rcpts_virus sender_archive \
		sender_cured sender_error sender_malware sender_skip sender_virus

do-install:
	${INSTALL_PROGRAM} -m 0750 -o drweb -g drweb \
		${WRKSRC}${LOCALBASE}/drweb/drweb-smf ${INST_PREFIX}/drweb-smf
.for CONF in ${CONFS}
	${SED} -e s#/usr/local/drweb/run#/var/drweb/run#g \
		< ${WRKSRC}${LOCALBASE}/etc/drweb/${CONF}.conf > \
		${CONF_PREFIX}/${CONF}.conf-distr
.if !exists( ${CONF_PREFIX}/${CONF}.conf )
	${CP} ${CONF_PREFIX}/${CONF}.conf-distr ${CONF_PREFIX}/${CONF}.conf
.endif
.endfor
.for LANG in ${LANGS}
	${MKDIR} ${CONF_PREFIX}/templates/${LANG}/sendmail
.endfor
.for LANG in ${LANGS}
.for TMPL in ${TMPLS}
	${INSTALL} -m 0640 -o drweb -g drweb ${WRKSRC}${LOCALBASE}/etc/drweb/templates/${LANG}/${TMPL}.msg \
		${CONF_PREFIX}/templates/${LANG}/sendmail/${TMPL}.msg-distr
.if !exists( ${CONF_PREFIX}/templates/${LANG}/sendmail/${TMPL}.msg )
	${CP} ${CONF_PREFIX}/templates/${LANG}/sendmail/${TMPL}.msg-distr \
		${CONF_PREFIX}/templates/${LANG}/sendmail/${TMPL}.msg
.endif
.endfor
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${TAR} -cf - -C ${WRKSRC}${LOCALBASE}/drweb/doc/sendmail . | \
		${TAR} -xf - -C ${DOCSDIR} --exclude "configure*" \
			--exclude "*.patch" --exclude "template.*"
.endif
	@${ECHO}
	@${ECHO} "Read documentation about additional Sendmail tuning needed"
	@${ECHO} "in ${DOCSDIR}."
	@${ECHO}

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	ldap-account-manager
PORTVERSION=	4.4
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${SHORTNAME}/LAM/${PORTVERSION}

MAINTAINER=	basil@vpm.net.ua
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Quota>=0:${PORTSDIR}/sysutils/p5-Quota \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

NO_BUILD=	yes
USES=		gettext perl5
USE_PHP=	gettext hash iconv ldap mcrypt pcre session simplexml spl xml json zip openssl
USE_BZIP2=	yes
WANT_PHP_WEB=	yes

SHORTNAME=	lam
PORTDOCS=	docs HISTORY README copyright
LAMDATA=	config graphics help lib locale sess style templates tmp VERSION index.html .htaccess
WWWDIR=		${PREFIX}/www/${SHORTNAME}
SUB_FILES=	pkg-message
CONFIGS=	config.cfg lam.conf
WRITEABLES=	config sess tmp

.include <bsd.port.options.mk>

do-install:
	@${ECHO_CMD} '@unexec if [ -f %D/${WWWDIR_REL}/config/shells ]; then ${RM} -f %D/${WWWDIR_REL}/config/shells; fi' >> ${TMPPLIST}
.for CONFIG in ${CONFIGS}
	@${ECHO_CMD} '@unexec if cmp -s %D/${WWWDIR_REL}/config/${CONFIG}_sample %D/${WWWDIR_REL}/config/${CONFIG}; then ${RM} -f %D/${WWWDIR_REL}/config/${CONFIG}; fi' >> ${TMPPLIST}
.endfor
.for I in ${LAMDATA}
	@${FIND} -s ${WRKSRC}/${I} -type f -not -name '${CONFIGS}'| ${SED} -e 's,^${WRKSRC},${WWWDIR_REL},' >> ${TMPPLIST}
	@${FIND} -ds ${WRKSRC}/${I} -type d | ${SED} -e 's,^${WRKSRC},@dirrm ${WWWDIR_REL},' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} '@dirrm ${WWWDIR_REL}' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${LAMDATA}" ${STAGEDIR}${WWWDIR}
.for CONFIG in ${CONFIGS}
	@${ECHO_CMD} '@exec if [ ! -f %D/${WWWDIR_REL}/config/${CONFIG} ]; then ${CP} %D/${WWWDIR_REL}/config/${CONFIG}_sample %D/${WWWDIR_REL}/config/${CONFIG}; ${CHOWN} ${WWWOWN} %D/${WWWDIR_REL}/config/${CONFIG}; fi' >> ${TMPPLIST}
.if !exists(${STAGEDIR}${WWWDIR}/config/${CONFIG})
	@${CP} ${STAGEDIR}${WWWDIR}/config/${CONFIG}_sample ${STAGEDIR}${WWWDIR}/config/${CONFIG}
.endif
.endfor
.for DIR in ${WRITEABLES}
	@${CHOWN} -R ${WWWOWN} ${STAGEDIR}${WWWDIR}/${DIR}
	@${CHMOD} -R u+w ${STAGEDIR}${WWWDIR}/${DIR}
	@${CHMOD} u+x ${STAGEDIR}${WWWDIR}/lib/lamdaemon.pl
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN} %D/${WWWDIR_REL}/${DIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R u+w %D/${WWWDIR_REL}/${DIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} u+x %D/${WWWDIR_REL}/lib/lamdaemon.pl' >> ${TMPPLIST}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

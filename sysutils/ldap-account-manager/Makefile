PORTNAME=	ldap-account-manager
PORTVERSION=	7.3
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${SHORTNAME}/LAM/${PORTVERSION}

MAINTAINER=	basil@vpm.net.ua
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Quota>=0:sysutils/p5-Quota \
		p5-perl-ldap>=0:net/p5-perl-ldap

USES=		perl5 php:web tar:bzip2
USE_PHP=	curl gd gettext gmp hash iconv json ldap openssl pcre \
		session simplexml xml xmlreader xmlwriter zip

NO_BUILD=	yes
NO_ARCH=	yes

SHORTNAME=	lam
PORTDOCS=	docs HISTORY README copyright
LAMDATA=	config graphics help lib locale sess style templates tmp VERSION index.html .htaccess
WWWDIR=		${PREFIX}/www/${SHORTNAME}
CONFIGS=	config.cfg addressbook.conf samba3.conf unix.conf windows_samba4.conf
WRITEABLES=	config sess tmp

OPTIONS_DEFINE=	DOCS

do-install:
	@${ECHO_CMD} '@preexec if [ -f %D/${WWWDIR_REL}/config/shells ]; then ${RM} %D/${WWWDIR_REL}/config/shells; fi' >> ${TMPPLIST}
.for CONFIG in ${CONFIGS}
	@${ECHO_CMD} '@sample ${WWWDIR_REL}/config/${CONFIG}.sample' >> ${TMPPLIST}
	@${ECHO_CMD} '@postexec if [ -f %D/${WWWDIR_REL}/config/${CONFIG}_sample ]; then ${RM} %D/${WWWDIR_REL}/config/${CONFIG}_sample; fi' >> ${TMPPLIST}
.endfor
.for I in ${LAMDATA}
	@${FIND} -s ${WRKSRC}/${I} -type f -not -name '*.sample' | ${SED} -e 's,^${WRKSRC},${WWWDIR_REL},' >> ${TMPPLIST}
	@${FIND} -ds ${WRKSRC}/${I} -type d | ${SED} -e 's,^${WRKSRC},@dir ${WWWDIR_REL},' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} '@dir ${WWWDIR_REL}' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${LAMDATA}" ${STAGEDIR}${WWWDIR}
.for DIR in ${WRITEABLES}
	@${ECHO_CMD} '@postexec ${CHOWN} -R ${WWWOWN} %D/${WWWDIR_REL}/${DIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@postexec ${CHMOD} -R u+w %D/${WWWDIR_REL}/${DIR}' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} '@postexec ${CHOWN} ${WWWOWN} %D/${WWWDIR_REL}/${DIR}/lib/lamdaemon.pl' >> ${TMPPLIST}
	@${ECHO_CMD} '@postexec ${CHMOD} u+x %D/${WWWDIR_REL}/${DIR}/lib/lamdaemon.pl' >> ${TMPPLIST}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

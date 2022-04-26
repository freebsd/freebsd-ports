PORTNAME=	ldap-account-manager
PORTVERSION=	7.9
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${SHORTNAME}/LAM/${PORTVERSION}

MAINTAINER=	basil@vpm.net.ua
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Quota>=0:sysutils/p5-Quota p5-perl-ldap>=0:net/p5-perl-ldap

USES=		perl5 php:web tar:bzip2
USE_PHP=	curl gd filter gettext gmp hash iconv json ldap mbstring openssl \
		pcre session simplexml xml xmlreader xmlwriter zip

WWWDIR=		${PREFIX}/www/${SHORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

SHORTNAME=	lam
PORTDOCS=	docs COPYING HISTORY README copyright
LAMDATA=	config graphics help lib locale sess style templates tmp VERSION index.html pwa_worker.js .htaccess
WRITEABLES=	config sess tmp

OPTIONS_DEFINE+=DOCS
OPTIONS_DEFAULT=DOCS

DOCS_DESC=	Install documentation and dhcp.schema

.include <bsd.port.options.mk>

do-install:
	@${ECHO_CMD} '@preexec if [ -f %D/${WWWDIR_REL}/config/shells ]; then ${RM} %D/${WWWDIR_REL}/config/shells; fi' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample ${WWWDIR_REL}/config/addressbook.sample.conf ${WWWDIR_REL}/config/addressbook.conf' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample ${WWWDIR_REL}/config/config.cfg.sample ${WWWDIR_REL}/config/config.cfg' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample ${WWWDIR_REL}/config/samba3.sample.conf ${WWWDIR_REL}/config/samba3.conf' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample ${WWWDIR_REL}/config/unix.sample.conf ${WWWDIR_REL}/config/lam.conf' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample ${WWWDIR_REL}/config/windows_samba4.sample.conf ${WWWDIR_REL}/config/windows_samba4.conf' >> ${TMPPLIST}
.for I in ${LAMDATA}
	@${FIND} -s ${WRKSRC}/${I} -type f -not -name 'config.cfg.sample' -not -name '*.sample.conf' | ${SED} -e 's,^${WRKSRC},${WWWDIR_REL},' >> ${TMPPLIST}
	@${FIND} -ds ${WRKSRC}/${I} -type d | ${SED} -e 's,^${WRKSRC},@dir ${WWWDIR_REL},' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} '@dir ${WWWDIR_REL}' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${LAMDATA}" ${STAGEDIR}${WWWDIR}
.for DIR in ${WRITEABLES}
	@${ECHO_CMD} '@postexec ${CHOWN} -R ${WWWOWN} %D/${WWWDIR_REL}/${DIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@postexec ${CHMOD} -R u+w %D/${WWWDIR_REL}/${DIR}' >> ${TMPPLIST}
.endfor
	@${SED} -i '' 's|usr/bin/perl|usr/local/bin/perl|g' ${WRKSRC}/lib/lamdaemon.pl
	@${ECHO_CMD} '@postexec ${CHOWN} ${WWWOWN} %D/${WWWDIR_REL}/${DIR}/lib/lamdaemon.pl' >> ${TMPPLIST}
	@${ECHO_CMD} '@postexec ${CHMOD} u+x %D/${WWWDIR_REL}/${DIR}/lib/lamdaemon.pl' >> ${TMPPLIST}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

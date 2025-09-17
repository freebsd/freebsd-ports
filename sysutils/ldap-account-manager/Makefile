PORTNAME=	ldap-account-manager
DISTVERSION=	9.3
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${SHORTNAME}/LAM/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server
WWW=		https://www.ldap-account-manager.org/lamcms/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Quota>=0:sysutils/p5-Quota

USES=		perl5 php:web shebangfix tar:bzip2
USE_PHP=	curl filter gd gettext gmp iconv ldap mbstring \
		session simplexml xml xmlreader xmlwriter zip

SHEBANG_FILES=	lib/lamdaemon.pl

WWWDIR=		${PREFIX}/www/${SHORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PORTDOCS=	COPYING HISTORY README copyright docs
OPTIONS_DEFINE=	DOCS

DOCS_DESC=	Install documentation and dhcp.schema

LAMDATA=	config graphics help lib locale sess style templates tmp \
		VERSION index.html pwa_worker.js .htaccess
SHORTNAME=	lam

do-install:
	@${ECHO_CMD} '@rmtry ${WWWDIR_REL}/config/shells' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample(${WWWOWN},,) ${WWWDIR_REL}/config/addressbook.sample.conf ${WWWDIR_REL}/config/addressbook.conf' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample(${WWWOWN},,) ${WWWDIR_REL}/config/config.cfg.sample ${WWWDIR_REL}/config/config.cfg' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample(${WWWOWN},,) ${WWWDIR_REL}/config/samba3.sample.conf ${WWWDIR_REL}/config/samba3.conf' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample(${WWWOWN},,) ${WWWDIR_REL}/config/unix.sample.conf ${WWWDIR_REL}/config/lam.conf' >> ${TMPPLIST}
	@${ECHO_CMD} '@sample(${WWWOWN},,) ${WWWDIR_REL}/config/windows_samba4.sample.conf ${WWWDIR_REL}/config/windows_samba4.conf' >> ${TMPPLIST}
.for I in ${LAMDATA}
	@${FIND} -s ${WRKSRC}/${I} -type f -not -name 'config.cfg.sample' -not -name '*.sample.conf' | \
		${SED} -e 's#^${WRKSRC}#${WWWDIR_REL}#' | \
		${SED} -E -e '/lib\/lamdaemon.pl$$/ s#^#@(${WWWOWN},,0544) #; \
			/\/config|\/sess|\/tmp/ s#^#@(${WWWOWN},,) #;' >> ${TMPPLIST}
	@${FIND} -ds ${WRKSRC}/${I} -type d | \
		${SED} -e 's,^${WRKSRC},@dir ${WWWDIR_REL},' | \
		${SED} -E -e '/\/config\/|\/sess\/|\/tmp\// s#@dir #@dir(${WWWOWN},,0755) #' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} '@dir ${WWWDIR_REL}' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${LAMDATA}" ${STAGEDIR}${WWWDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Bob Hockney <zeus@ix.netcom.com>
# $FreeBSD$

PORTNAME=	webfwlog
PORTVERSION=	0.94
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

PATCHFILES=	webfwlog-0.94-tcpflags.patch
PATCH_SITES=	http://devel.webfwlog.net/download/patches/

MAINTAINER=	zeus@ix.netcom.com
COMMENT=	A web-based firewall log analyzer

OPTIONS_DEFINE=		MYSQL PGSQL EXAMPLES
OPTIONS_DEFAULTS=	MYSQL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-html-doc-root=${PREFIX}
CONFIGURE_ARGS+=	--enable-syslog

USE_PHP=	session pcre
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message
SUB_LIST+=	VERSION=${PORTVERSION}

PORTDOCS=	AUTHORS COPYING CREDITS ChangeLog INSTALL \
		README ReleaseNotes
PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql
.endif

BINMODE=	4550
BINGRP=	${WWWGRP}

do-install:
	@${MKDIR} ${WWWDIR}
	@${MKDIR} ${WWWDIR}/include/
	@(cd ${WRKSRC}/webfwlog/include/ && ${COPYTREE_SHARE} \*.php ${WWWDIR}/include/)
	${CHMOD} 555 ${WWWDIR}/include
	${INSTALL_PROGRAM} ${WRKSRC}/syslog/wfwl_syslog ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/webfwlog/style.css ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webfwlog/index.php ${WWWDIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/mysql
	@${MKDIR} ${DOCSDIR}/pgsql
	@(cd ${WRKSRC}/mysql/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/mysql/)
	@(cd ${WRKSRC}/pgsql/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/pgsql/)
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

	@if test -f ${PREFIX}/etc/webfwlog.conf; \
	then \
		${CHOWN} :${WWWGRP} ${PREFIX}/etc/webfwlog.conf; \
		${CHMOD} 0640 ${PREFIX}/etc/webfwlog.conf; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/webfwlog.conf ${PREFIX}/etc/webfwlog.conf.sample
	@${CHOWN} :${WWWGRP} ${PREFIX}/etc/webfwlog.conf.sample
	@${CHMOD} 0640 ${PREFIX}/etc/webfwlog.conf.sample
	@if test -f ${PREFIX}/etc/webfwlog.conf && \
		test -f ${PREFIX}/etc/webfwlog.conf.sample && \
		test "`diff ${PREFIX}/etc/webfwlog.conf ${PREFIX}/etc/webfwlog.conf.sample`" ; \
	then :; \
	else \
		${RM} -f ${PREFIX}/etc/webfwlog.conf; \
	fi
	@${RM} -f ${PREFIX}/etc/webfwlog.conf.new

	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>

# New ports collection makefile for:   webfwlog
# Date created:        21 November 2004
# Whom:                Bob Hockney <zeus@ix.netcom.com>
#
# $FreeBSD$
#

PORTNAME=	webfwlog
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zeus@ix.netcom.com
COMMENT=	A web-based firewall log analyzer

OPTIONS=	MYSQL "Include MySQL Support" on \
		POSTGRESQL "Include PostgreSQL Support" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-html-doc-root=${PREFIX}/${HTML_DOC_ROOT}
CONFIGURE_ARGS+=--enable-syslog

USE_PHP=	yes
WANT_PHP_WEB=	yes

# Set HTML_DOC_ROOT to your webserver's Document Root where you
# want to install webfwlog, relative to ${PREFIX}.

SUB_FILES=	pkg-message
DOCS=		README AUTHORS COPYING \
		CREDITS ChangeLog INSTALL \
		README ReleaseNotes

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=
CONFIGURE_ARGS+=--with-pgsql
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${MKDIR} ${WWWDIR}/include/
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
	@(cd ${WRKSRC}/webfwlog/include/ && ${COPYTREE_SHARE} \* ${WWWDIR}/include/)
	${INSTALL_PROGRAM} ${WRKSRC}/syslog/wfwl_syslog ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/webfwlog/style.css ${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webfwlog/index.php ${WWWDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/mysql
	@${MKDIR} ${DOCSDIR}/pgsql
	@(cd ${WRKSRC}/mysql/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/mysql/)
	@(cd ${WRKSRC}/pgsql/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/pgsql/)
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
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

.include <bsd.port.post.mk>

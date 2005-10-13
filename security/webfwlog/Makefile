# New ports collection makefile for:   webfwlog
# Date created:        21 November 2004
# Whom:                Bob Hockney <zeus@ix.netcom.com>
#
# $FreeBSD$
#

PORTNAME=	webfwlog
PORTVERSION=	0.91
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://devel.webfwlog.net/download/patches/
PATCHFILES=	webfwlog-0.91-order_state.patch
PATCH_DIST_STRIP=	-p1

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

HTML_DOC_ROOT?=	www/data

PLIST_SUB=	HTML_DOC_ROOT=${HTML_DOC_ROOT}

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=
CONFIGURE_ARGS+=--with-pgsql
.endif

BINGRP=		${WWWGRP}
BINMODE=	4550

pre-install:
	@${MKDIR} ${PREFIX}/${HTML_DOC_ROOT}

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/COPYING ${WRKSRC}/AUTHORS ${WRKSRC}/README \
		${WRKSRC}/INSTALL ${WRKSRC}/CREDITS ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/ChangeLog ${WRKSRC}/ReleaseNotes ${DOCSDIR}

	@${MKDIR} ${DOCSDIR}/mysql/scripts
	@${INSTALL_MAN} ${WRKSRC}/mysql/README ${WRKSRC}/mysql/setup ${DOCSDIR}/mysql
	@${INSTALL_MAN} ${WRKSRC}/mysql/scripts/* ${DOCSDIR}/mysql/scripts
	@${CHMOD} a+x ${DOCSDIR}/mysql/setup

	@${MKDIR} ${DOCSDIR}/pgsql/scripts
	@${INSTALL_MAN} ${WRKSRC}/pgsql/README ${WRKSRC}/pgsql/setup ${DOCSDIR}/pgsql
	@${INSTALL_MAN} ${WRKSRC}/pgsql/scripts/* ${DOCSDIR}/pgsql/scripts
	@${CHMOD} a+x ${DOCSDIR}/pgsql/setup

	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/examples/* ${EXAMPLESDIR}
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
	@${CHMOD} 0555 ${PREFIX}/${HTML_DOC_ROOT}/webfwlog
	@${CHMOD} 0555 ${PREFIX}/${HTML_DOC_ROOT}/webfwlog/include

	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.post.mk>

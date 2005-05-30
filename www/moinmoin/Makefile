# New ports collection makefile for:	moinmoin
# Date created:				18 September 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	moinmoin
PORTVERSION=	1.3.4
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	moin
DISTNAME=	moin-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	A Python clone of WikiWiki

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}
SUB_FILES=	pkg-install
SUB_LIST=	MOINDIR=${MOINDIR} MOINDEST=${MOINDEST}

CGIUSER?=	www
CGIGROUP?=	www
MOINDIR=	${PREFIX}/share/moin
MOINDEST?=	${PREFIX}/www/wiki
MOINTYPE?=	CGI

PKGDEINSTALL=	${PKGINSTALL}

.if ${MOINTYPE} == "STANDALONE"
MOINSCRIPT=	${MOINDIR}/server/moin.py
.elif ${MOINTYPE} == "FCGI"
MOINSCRIPT=	${MOINDIR}/server/moin.fcg
.elif ${MOINTYPE} == "MOD_PYTHON"
.elif ${MOINTYPE} == "CGI"
MOINSCRIPT=	${MOINDIR}/server/moin.cgi
.else
IGNORE=		"MOINTYPE must be a STANDALONE, FCGI, MOD_PYTHON or CGI."
.endif

pre-everything::
	@${ECHO}
	@${ECHO} "Set MOINTYPE=(CGI|FCGI|STANDALONE) to define"
	@${ECHO} "type of installation. Default is CGI."
	@${ECHO} "Use MOINDEST=/path to modify installation destination."
	@${ECHO} "Default value for MOINDEST is ${PREFIX}/www/wiki."
	@${ECHO}
	@${ECHO} "To get correct permissions, please set CGIUSER, CGIGROUP"
	@${ECHO} "per default it is set to www:www."
	@${ECHO}
	@${MKDIR} ${WRKDIR}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

instance: pre-everything apply-slist
	@${ECHO_CMD} "Creating a new wiki instance in ${MOINDEST}."; \
	if [ -f ${MOINDIR}/config/wikiconfig.py ]; then \
		${MKDIR} ${MOINDEST}; \
		${CP} -R ${MOINDIR}/data ${MOINDEST}; \
		${CP} -R ${MOINDIR}/underlay ${MOINDEST}; \
		${CHMOD} -R u+rw,go-ws ${MOINDEST}/data; \
		${INSTALL_SCRIPT} ${MOINDIR}/config/wikiconfig.py ${MOINDEST}; \
		if [ ! -z ${MOINSCRIPT} ]; then \
			${INSTALL_SCRIPT} ${MOINSCRIPT} ${MOINDEST}; \
		fi; \
		${CHOWN} -R ${CGIUSER}:${CGIGROUP} ${MOINDEST}; \
		${SH} ${PKGINSTALL} ${PKGNAME} INSTANCE ${MOINTYPE}; \
	else \
		${ECHO_CMD} "You need to install moinmoin first before trying"; \
		${ECHO_CMD} "to add a new wiki instance."; \
	fi

.include <bsd.port.mk>

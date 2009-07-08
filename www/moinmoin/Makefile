# New ports collection makefile for:	moinmoin
# Date created:				18 September 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	moinmoin
PORTVERSION=	1.8.4
CATEGORIES=	www python
MASTER_SITES=	http://static.moinmo.in/files/
DISTNAME=	moin-${PORTVERSION}

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	A Python clone of WikiWiki

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	moin

PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||} \
		DATADIR=share/moin
SUB_FILES=	pkg-install
SUB_LIST=	MOINDIR=${MOINDIR} MOINDEST=${MOINDEST}

CGIUSER?=	www
CGIGROUP?=	www
MOINDIR=	${PREFIX}/share/moin
MOINDEST?=	${PREFIX}/www/wiki
MOINTYPE?=	CGI

PKGDEINSTALL=	${PKGINSTALL}

.if ${MOINTYPE} == "STANDALONE"
MOINSCRIPT=	${MOINDIR}/server/wikiserver.py
.elif ${MOINTYPE} == "FCGI"
MOINSCRIPT=	${MOINDIR}/server/moin.fcg
.elif ${MOINTYPE} == "MOD_PYTHON"
.elif ${MOINTYPE} == "CGI"
MOINSCRIPT=	${MOINDIR}/server/moin.cgi
.else
BROKEN=		MOINTYPE must be a STANDALONE, FCGI, MOD_PYTHON or CGI.
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

post-install:
#	@${FIND} ${PREFIX}/share/moin/underlay \! -type d | ${SED} -e 's,${PREFIX}/,,' >> ${TMPPLIST}
#	@${FIND} ${PREFIX}/share/moin/underlay -type d | ${SED} -e 's,${PREFIX}/,@dirrm ,' | ${SORT} -r >> ${TMPPLIST}
#	@${ECHO_CMD} "@dirrm share/moin" >> ${TMPPLIST}
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

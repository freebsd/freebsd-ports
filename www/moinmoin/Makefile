# New ports collection makefile for:	moinmoin
# Date created:				18 September 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	moinmoin
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	moin
DISTNAME=	moin-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}

CGIUSER?=	moinmoin
CGIUSERID?=	192
SUID_WRAPPER=	moin

WIKI_WRKSRC=	${WRKSRC}/MoinMoin/wiki-moinmoin
CGI_TARGET=	${PREFIX}/www/cgi-bin/moin
CGI_FILES=	${SUID_WRAPPER} moin.cgi moin_config.py data
CONTENT_TARGET=	${PREFIX}/www/data/moin
CONTENT_FILES=	PythonPowered.gif default.css img moinmoin.gif index.html
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-configure:
	@# Add the username, uid, group and gid
	${SH} ${FILESDIR}/configure.sh ${CGIUSER} ${CGIUSERID}

do-build:
	${SETUP_CMD} build
	@# Compile setuid wrapper
	${CC} ${CFLAGS} -o ${WIKI_WRKSRC}/${SUID_WRAPPER} \
		-DPYTHON_PATH='"${PYTHON_CMD}"' \
		-DSCRIPT_PATH='"${CGI_TARGET}/moin.cgi"' \
		${FILESDIR}/wrapper.c

do-install:
	@# Install MoinMoin library
	${SETUP_CMD} install

	@# Install CGI files and set permissions
	${MKDIR} ${CGI_TARGET}/data/backup
	cd ${WIKI_WRKSRC} && ${CP} -Rp ${CGI_FILES} ${CGI_TARGET}/
	${CHOWN} -R ${CGIUSER}:${CGIUSER} ${CGI_TARGET}/data \
		${CGI_TARGET}/${SUID_WRAPPER}
	${CHMOD} -R u+rw,go-wxs ${CGI_TARGET}/data
	${CHMOD} 4555 ${CGI_TARGET}/${SUID_WRAPPER}

	@# Install content files
	${MKDIR} ${CONTENT_TARGET}
	cd ${WIKI_WRKSRC} && ${CP} -Rp ${CONTENT_FILES} ${CONTENT_TARGET}/

	@# Patch configurations
	${SED} -e 's|moin\.cgi|/cgi-bin/moin/moin|g' \
		${CONTENT_TARGET}/index.html >${CONTENT_TARGET}/index.html.tmp
	${CAT} ${CONTENT_TARGET}/index.html.tmp >${CONTENT_TARGET}/index.html
	${SED} -e 's|^url_prefix =.*$$|url_prefix="/moin/"|g' \
		${CGI_TARGET}/moin_config.py >${CGI_TARGET}/moin_config.py.tmp
	${CAT} ${CGI_TARGET}/moin_config.py.tmp >${CGI_TARGET}/moin_config.py
	${RM} -f ${CONTENT_TARGET}/index.html.tmp ${CGI_TARGET}/moin_config.py.tmp

.include <bsd.port.mk>

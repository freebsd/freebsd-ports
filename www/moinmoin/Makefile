# New ports collection makefile for:	moinmoin
# Date created:				18 September 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	moinmoin
PORTVERSION=	0.9
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	moin
DISTNAME=	${PORTNAME:S/m/M/g}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@python.or.kr

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}

CGIUSER?=	moinmoin
CGIUSERID?=	192
SUID_WRAPPER=	moin

WIKI_WRKSRC=	${WRKSRC}/wiki-moinmoin
LIB_TARGET=	${PYTHON_SITELIBDIR}/MoinMoin
LIB_DIRS=	action formatter i18n macro parser py15 support twisted webapi .
CGI_TARGET=	${PREFIX}/www/cgi-bin/moin
CGI_FILES=	${SUID_WRAPPER} moin.cgi moin_config.py data
CONTENT_TARGET=	${PREFIX}/www/data/moin
CONTENT_FILES=	PythonPowered.gif default.css img moinmoin.gif index.html

do-configure:
	@# Add the username, uid, group and gid
	${SH} ${FILESDIR}/configure.sh ${CGIUSER} ${CGIUSERID}

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@# Compile setuid wrapper
	${CC} ${CFLAGS} -o ${WIKI_WRKSRC}/${SUID_WRAPPER} \
		-DPYTHON_PATH='"${PYTHON_CMD}"' \
		-DSCRIPT_PATH='"${CGI_TARGET}/moin.cgi"' \
		${FILESDIR}/wrapper.c

do-install:
	@# Install MoinMoin library
	${MKDIR} ${LIB_TARGET}
.for dir in ${LIB_DIRS}
	${MKDIR} ${LIB_TARGET}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.py* ${LIB_TARGET}/${dir}
.endfor
	@# Install CGI files and set permissions
	${MKDIR} ${CGI_TARGET}
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

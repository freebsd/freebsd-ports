# New ports collection makefile for:	moinmoin
# Date created:				18 September 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	moinmoin
PORTVERSION=	0.11
CATEGORIES=	www python
MASTER_SITES= 	http://twiki.org/p/pub/TWiki/TWikiDrawPlugin/ \
		${MASTER_SITE_SOURCEFORGE} \
		http://fallin.lv/distfiles/
MASTER_SITE_SUBDIR=	moin
DISTNAME=	moin-${PORTVERSION}
DISTFILES=	${DISTNAME}.tgz twikidraw.jar
EXTRACT_ONLY=	${DISTNAME}.tgz

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||}

CGIUSER?=	moinmoin
CGIUSERID?=	192
CGIROOT=	${PREFIX}/www/cgi-bin
HTDOCSROOT=	${PREFIX}/www/data
MOINDIR=	${PREFIX}/share/moin
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-configure:
	@# Add the username, uid, group and gid
	${SH} ${FILESDIR}/configure.sh ${CGIUSER} ${CGIUSERID}

post-patch:
	@# Tweak configuration
	${SED} -e 's|^url_prefix =.*$$|url_prefix="/moin"|g' \
		${WRKSRC}/wiki/cgi-bin/moin_config.py > \
		${WRKSRC}/wiki/cgi-bin/moin_config.py.default

do-build:
	${SETUP_CMD} build
	@# Compile setuid wrapper
	${CC} ${CFLAGS} -o ${WRKDIR}/moin \
		-DPYTHON_PATH='"${PYTHON_CMD}"' \
		-DMOIN_PREFIX='"${MOINDIR}"' \
		${FILESDIR}/wrapper.c

do-install:
	@# Install MoinMoin
	${SETUP_CMD} install
	${INSTALL_DATA} ${DISTDIR}/twikidraw.jar ${MOINDIR}/htdocs/applets/TWikiDrawPlugin/

	@# Install Wrapper
	${MKDIR} ${CGIROOT}
	${INSTALL_PROGRAM} ${WRKDIR}/moin ${CGIROOT}/
	${CHMOD} 4555 ${CGIROOT}/moin

	@# Arrange Permissions
	${MKDIR} ${MOINDIR}/data/backup
	${CHMOD} -R u+rw,go-wxs ${MOINDIR}/data
	${CHOWN} -R ${CGIUSER}:${CGIUSER} ${CGIROOT}/moin ${MOINDIR}/data

	@# Create symbolic links and copy defaults
	${TEST} -f ${MOINDIR}/cgi-bin/moin_config.py || \
		${CP} ${MOINDIR}/cgi-bin/moin_config.py.default \
			${MOINDIR}/cgi-bin/moin_config.py
	${TEST} -d ${MOINDIR}/data/text || \
		${LN} -sf ${MOINDIR}/data/text.default ${MOINDIR}/data/text
	-${LN} -sf ${MOINDIR}/htdocs ${HTDOCSROOT}/moin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

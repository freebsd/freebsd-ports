# New ports collection makefile for:	moinmoin
# Date created:				18 September 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	moinmoin
PORTVERSION=	1.2.3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	moin
DISTNAME=	moin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python CGI clone of WikiWiki

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||} \
		CGIUSER=${CGIUSER} CGIROOT=${CGIROOT}

CGIUSER=	moinmoin
CGIUSERID?=	192
CGIROOT=	${PREFIX}/www/cgi-bin
HTDOCSROOT=	${PREFIX}/www/data
MOINDIR=	${PREFIX}/share/moin

post-patch:
	@# Tweak configuration
	${SED} -e 's|^url_prefix =.*$$|url_prefix="/moin"|g' \
		${WRKSRC}/wiki/cgi-bin/moin_config.py > \
		${WRKSRC}/wiki/cgi-bin/moin_config.py.default

post-build:
	@# Compile setuid wrapper
	${CC} ${CFLAGS} -o ${WRKDIR}/moin \
		-DPYTHON_PATH='"${PYTHON_CMD}"' \
		-DMOIN_PREFIX='"${MOINDIR}"' \
		${FILESDIR}/wrapper.c

pre-install:
	PKG_PREFIX=${PREFIX} INST_UID="${CGIUSERID}" \
	${SH} pkg-install ${PKGNAME} PRE-INSTALL

post-install:
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
	-${MKDIR} ${HTDOCSROOT}
	-${LN} -sf ${MOINDIR}/htdocs ${HTDOCSROOT}/moin

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

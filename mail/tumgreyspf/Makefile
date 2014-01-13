# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tumgreyspf
PORTVERSION=	1.37
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.tummy.com/pub/tummy/tumgreyspf/ \
		ftp://ftp.tummy.com/pub/tummy/tumgreyspf/old-releases/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	External policy checker for the postfix mail server

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/spf.py:${PORTSDIR}/mail/py-spf

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USE_PYTHON=	2
USES=		shebangfix

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKSRC}/pkg-message
PORTDOCS=	*
SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		TUMGREYSPF_DIR=${TUMGREYSPF_DIR} \
		TUMGREYSPF_USER=${TUMGREYSPF_USER} \
		TUMGREYSPF_GROUP=${TUMGREYSPF_GROUP}

SHEBANG_FILES=	*
python_OLD_CMD=	${SETENV} python
python_CMD=	${PYTHON_CMD}

TUMGREYSPF_DIR?=	/var/db/${PORTNAME}
TUMGREYSPF_USER?=	nobody
TUMGREYSPF_GROUP?=	nobody

.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "TUMGREYSPF_DIR=/var/db/${PORTNAME}	Local are used to greylist (Default: /var/db/${PORTNAME})"
	@${ECHO_MSG} "TUMGREYSPF_USER=nobody			User to run ${PORTNAME} (Default: nobody)"
	@${ECHO_MSG} "TUMGREYSPF_GROUP=nobody			Group to run ${PORTNAME} (Default: nobody)"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e '/\/usr\/local\/lib\/tumgreyspf/d' \
		${WRKSRC}/tumgreyspf ${WRKSRC}/tumgreyspf-clean ${WRKSRC}/tumgreyspf-stat
	@${REINPLACE_CMD} -e '/configPath/ s|/var/local/lib/tumgreyspf|${TUMGREYSPF_DIR}|' \
		-e '/greylistDir/ s|/var/local/lib/tumgreyspf|${TUMGREYSPF_DIR}|' \
		-e '/spfqueryPath/ s|/usr/local/lib/tumgreyspf|${PREFIX}/bin|' \
		-e '/blackholeDir/ s|/var/lib/tumgreyspf|${TUMGREYSPF_DIR}|' \
		-e '/blackholeDir/ s|/var/local/lib/tumgreyspf|${TUMGREYSPF_DIR}|' \
		-e '/defaultConfigFilename/ s|/var/local/lib/tumgreyspf/config|${PREFIX}/etc|' \
			${WRKSRC}/tumgreyspf.conf ${WRKSRC}/tumgreyspfsupp.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/
	cd ${WRKSRC}/ && \
		${INSTALL_SCRIPT} tumgreyspf tumgreyspf-clean tumgreyspf-configtest tumgreyspf-stat ${STAGEDIR}${PREFIX}/bin/ && \
		${INSTALL_SCRIPT} gentest ${STAGEDIR}${PREFIX}/bin/tumgreyspf-gentest && \
		${INSTALL_SCRIPT} tumgreyspfsupp.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ && \
		${INSTALL_DATA} tumgreyspf.conf ${STAGEDIR}${PREFIX}/etc/tumgreyspf.conf.default
.if !exists(${PREFIX}/etc/tumgreyspf.conf)
	${INSTALL_DATA} ${WRKSRC}/tumgreyspf.conf ${STAGEDIR}${PREFIX}/etc/
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/__default__.dist ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}/
.if !defined(PACKAGE_BUILDING)
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>

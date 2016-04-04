# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tumgreyspf
PORTVERSION=	1.38
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.tummy.com/pub/tummy/tumgreyspf/ \
		ftp://ftp.tummy.com/pub/tummy/tumgreyspf/old-releases/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	External policy checker for the postfix mail server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyspf>=0:mail/py-pyspf

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
NO_BUILD=	yes
USES=		python shebangfix

PKGMESSAGE=	${WRKSRC}/pkg-message
PLIST_SUB=	TUMGREYSPF_DIR=${TUMGREYSPF_DIR} \
		TUMGREYSPF_USER=${TUMGREYSPF_USER} \
		TUMGREYSPF_GROUP=${TUMGREYSPF_GROUP}
PORTDOCS=	*
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		TUMGREYSPF_USER=${TUMGREYSPF_USER}

SHEBANG_FILES=	*

TUMGREYSPF_DIR?=	/var/db/${PORTNAME}
TUMGREYSPF_USER?=	nobody
TUMGREYSPF_GROUP?=	nobody

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
	cd ${WRKSRC}/ && ${INSTALL_SCRIPT} tumgreyspf tumgreyspf-clean tumgreyspf-configtest tumgreyspf-stat ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_SCRIPT} gentest ${STAGEDIR}${PREFIX}/bin/tumgreyspf-gentest
	cd ${WRKSRC}/ && ${INSTALL_SCRIPT} tumgreyspfsupp.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} tumgreyspf.conf ${STAGEDIR}${PREFIX}/etc/tumgreyspf.conf.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/__default__.dist ${STAGEDIR}${DATADIR}/__default__.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}/
	${MKDIR} -m 755 -p ${STAGEDIR}${TUMGREYSPF_DIR}
	${MKDIR} -m 755 ${STAGEDIR}${TUMGREYSPF_DIR}/config
	${MKDIR} -m 700 ${STAGEDIR}${TUMGREYSPF_DIR}/data

.include <bsd.port.mk>

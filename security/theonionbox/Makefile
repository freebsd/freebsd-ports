# $FreeBSD$

PORTNAME=	theonionbox
PORTVERSION=	4.2.1
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web interface to monitor Tor node operation

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apscheduler>=3.4:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bottle>=0.12.13:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.4.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=1.6.7:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>2.18:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=1.5.4:security/py-stem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.4:devel/py-tzlocal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.22:net/py-urllib3@${PY_FLAVOR}
py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}futures>=3.2:devel/py-futures@${PY_FLAVOR}

USES=		dos2unix python
DOS2UNIX_FILES=	FreeBSD/${PORTNAME}.sh
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

POST_PLIST=	correct-plist

OPTIONS_DEFINE=	DOCS

post-patch:
	@${MV} ${WRKSRC}/FreeBSD/${PORTNAME}.sh ${WRKSRC}/FreeBSD/${PORTNAME}
	@${REINPLACE_CMD} ' \
		s|"/your/path/to/${PORTNAME}"|"${PREFIX}"|; \
		s|${PORTNAME}_dir}/${PORTNAME}\.py|${PORTNAME}_dir}/bin/${PORTNAME}|; \
		s|/config/${PORTNAME}.cfg|/etc/${PORTNAME}/${PORTNAME}|; \
		s|"/usr/local/bin/python"|"${PYTHON_CMD}"|' \
		${WRKSRC}/FreeBSD/${PORTNAME}

post-patch-DOCS-off:
	@${REINPLACE_CMD} "s|('share/doc/${PORTNAME}', \['docs/\*\.\*'\]),||" ${WRKSRC}/setup.py

post-install:
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}

correct-plist:
	@${REINPLACE_CMD} ' \
		s|^etc/${PORTNAME}/${PORTNAME}.example$$|@sample & etc/${PORTNAME}/${PORTNAME}|; \
		s|^etc/${PORTNAME}$$|@dir &|; \
		s|^etc/rc.d$$|@dir &|; \
		s|^share/doc/${PORTNAME}$$|@dir &|' \
		${TMPPLIST}

.include <bsd.port.mk>

PORTNAME=	tlsrpt-reporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Collectd, fetcher and reportd software for SMTP TLS reporting
WWW=		https://github.com/sys4/tlsrpt-reporter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=1.2.2:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR} \
		asciidoctor:textproc/rubygem-asciidoctor
RUN_DEPENDS=	curl:ftp/curl \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		gmake python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	sys4

USE_PYTHON=	autoplist pep517 unittest

NO_ARCH=	yes
USERS?=		_tlsrpt
GROUPS?=	_tlsrpt

SHEBANG_FILES=	./tlsrpt_reporter/tlsrpt_*.py

CFGFILE=	${ETCDIR}/${PORTNAME}.cfg

USE_RC_SUBR=	tlsrpt-collectd \
		tlsrpt-reportd
SUB_FILES=	${PORTNAME}.cfg
SUB_LIST=	RUNDIR=/var/run/${PORTNAME} \
		DBDIR=/var/db/${PORTNAME} \
		LOGDIR=/var/log/${PORTNAME} \
		PYTHON_CMD=${PYTHON_CMD} \
		CFGFILE=${CFGFILE} \
		USER=${USERS} \
		GROUP=${GROUPS}

PLIST_FILES=	"@sample ${CFGFILE}.sample" \
		share/man/man1/tlsrpt-collectd.1.gz \
		share/man/man1/tlsrpt-fetcher.1.gz \
		share/man/man1/tlsrpt-reportd.1.gz

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-build:
	(cd ${WRKSRC}/doc && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.cfg ${STAGEDIR}${CFGFILE}.sample
	(cd ${WRKSRC}/doc && \
	    ${INSTALL_MAN} ./*.1 ${STAGEDIR}${PREFIX}/share/man/man1)

.include <bsd.port.mk>

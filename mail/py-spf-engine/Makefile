PORTNAME=	spf-engine
DISTVERSION=	2.9.3
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	SPF engine for Postfix policy server and milter implemented in Python

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/GPL-2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}milter>0:mail/py-milter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyspf>0:mail/py-pyspf@${PY_FLAVOR}

USES=		python:3.3+ shebangfix
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	pyspf-milter

SHEBANG_FILES=	spf_engine/milter_spf.py spf_engine/policyd_spf.py

CONFLICTS=	py*-postfix-policyd-spf-python

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYSPF_MILTER_RUNDIR=${PYSPF_MILTER_RUNDIR} \
		PYTHON_CMD=${PYTHON_CMD}

USERS=		pyspf-milter
GROUPS=		pyspf-milter

PYSPF_MILTER_RUNDIR=	/var/run/pyspf-milter

PLIST_FILES=	'@dir(${USERS},${GROUPS},755) ${PYSPF_MILTER_RUNDIR}' \
		'@sample etc/python-policyd-spf/policyd-spf.conf.sample'

PORTDOCS=	CHANGES README README.per_user_whitelisting \
		policyd-spf.conf.commented

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/spf_engine/milter_spf.py
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/spf_engine/policyd_spf.py
	@${REINPLACE_CMD} -e "s|/run|/var/run|" ${WRKSRC}/spf_engine/policydspfsupp.py
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" -e "s|/usr/bin/|${PREFIX}/bin/|" \
		${WRKSRC}/policyd-spf.1 ${WRKSRC}/policyd-spf.conf.5 \
		${WRKSRC}/policyd-spf.peruser.5

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/pyspf-milter \
		${STAGEDIR}${PREFIX}/etc/python-policyd-spf
	${INSTALL_DATA} ${WRKSRC}/policyd-spf.conf \
		${STAGEDIR}${PREFIX}/etc/python-policyd-spf/policyd-spf.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

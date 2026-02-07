PORTNAME=	spf-engine
DISTVERSION=	3.1.0
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SPF engine for Postfix policy server and milter implemented in Python
WWW=		https://launchpad.net/spf-engine

LICENSE=	APACHE20 GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymilter>0:mail/py-pymilter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyspf>0:mail/py-pyspf@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517
USE_RC_SUBR=	pyspf-milter

SHEBANG_FILES=	spf_engine/milter_spf.py spf_engine/policyd_spf.py

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USERS=		pyspf-milter
GROUPS=		pyspf-milter

PLIST_FILES=	'@dir(${USERS},${GROUPS},755) /var/run/pyspf-milter' \
		'@sample etc/pyspf-milter/pyspf-milter.conf.sample' \
		'@sample etc/python-policyd-spf/policyd-spf.conf.sample'

PORTDOCS=	CHANGES README.per_user_whitelisting README.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/data/share/doc/python-policyd-spf/README.per_user_whitelisting \
		${WRKSRC}/data/share/man/man1/policyd-spf.1 \
		${WRKSRC}/data/share/man/man5/policyd-spf.conf.5 \
		${WRKSRC}/data/share/man/man5/policyd-spf.peruser.5 \
		${WRKSRC}/spf_engine/milter_spf.py ${WRKSRC}/spf_engine/policyd_spf.py
	@${FIND} ${WRKSRC} \( -name '*.bak' -or -name '*.orig' \) -delete
	@${MV} ${WRKSRC}/data/etc/pyspf-milter/pyspf-milter.conf \
		${WRKSRC}/data/etc/python-policyd-spf/policyd-spf.conf \
		${WRKSRC}/data/share/doc/python-policyd-spf/README.per_user_whitelisting \
		${WRKSRC}
	@${RM} -r ${WRKSRC}/data/etc/init.d ${WRKSRC}/data/etc/pyspf-milter \
		${WRKSRC}/data/lib ${WRKSRC}/data/share/doc

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/pyspf-milter \
		${STAGEDIR}${PREFIX}/etc/pyspf-milter
	${INSTALL_DATA} ${WRKSRC}/pyspf-milter.conf \
		${STAGEDIR}${PREFIX}/etc/pyspf-milter/pyspf-milter.conf.sample
	${INSTALL_DATA} ${WRKSRC}/policyd-spf.conf \
		${STAGEDIR}${PREFIX}/etc/python-policyd-spf/policyd-spf.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

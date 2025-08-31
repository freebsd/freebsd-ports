PORTNAME=	moin
DISTVERSION=	2.0.0b3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	https://github.com/moinwiki/moin/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	2

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Easy to use, full-featured and extensible wiki software package
WWW=		https://moinmo.in/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.10.0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.6.2:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.18.1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}emeraldtree>=0.10.0:textproc/py-emeraldtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedgen>=0.9.0:www/py-feedgen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=3.0.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-babel>=3.0.0:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-caching>=1.2.0:www/py-flask-caching@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-theme>=0.3.6:www/py-flask-theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flatland>=0.8:devel/py-flatland@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.4.1:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.2.0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mdx_wikilink_plus>=1.4.1:textproc/py-mdx_wikilink_plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6.0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>0:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.4:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=3.0.0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.7.0:textproc/py-whoosh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic>=0.0.2:devel/py-xstatic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-autosize>0:devel/py-xstatic-autosize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-bootstrap3>=3.1.1.2:devel/py-xstatic-bootstrap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-ckeditor>=3.6.1.2:devel/py-xstatic-ckeditor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-font-awesome>=6.2.1.0:devel/py-xstatic-font-awesome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-jquery>=1.8.2:devel/py-xstatic-jquery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-jquery-file-upload>=10.31.0:devel/py-xstatic-jquery-file-upload@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-jquery.tablesorter>=2.14.5.1:devel/py-xstatic-jquery.tablesorter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-pygments>=1.6.0.1:devel/py-xstatic-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xstatic-svg-edit-moin>=2012.11.15.1:devel/py-xstatic-svg-edit-moin@${PY_FLAVOR}

USES=		cpe python shebangfix
CPE_VENDOR=	moinmo
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

PLIST_SUB+=	PYTHON_SITELIB=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||} \
		DATADIR=share/moin
SUB_FILES=	pkg-install
SUB_LIST=	MOINDIR=${MOINDIR} MOINDEST=${MOINDEST} MOINVER=${MOINVER} \
		HTDOCS=${PYTHON_SITELIBDIR}/MoinMoin/web/static/htdocs

CGIUSER?=	www
CGIGROUP?=	www
MOINDIR=	${PREFIX}/share/moin
MOINDEST?=	${PREFIX}/www/wiki
MOINVER?=	${PORTVERSION:S|.||g}
MOINTYPE?=	CGI

PKGDEINSTALL=	${PKGINSTALL}

.if ${MOINTYPE} == "STANDALONE"
MOINSCRIPT=	${MOINDIR}/server/moin
.elif ${MOINTYPE} == "FCGI"
MOINSCRIPT=	${MOINDIR}/server/moin.fcgi
.elif ${MOINTYPE} == "MOD_PYTHON"
.elif ${MOINTYPE} == "CGI"
MOINSCRIPT=	${MOINDIR}/server/moin.cgi
.elif ${MOINTYPE} == "WSGI"
MOINSCRIPT=	${MOINDIR}/server/moin.wsgi
.else
BROKEN=		MOINTYPE must be a STANDALONE, FCGI, WSGI, MOD_PYTHON, or CGI
.endif

pre-everything::
	@${ECHO}
	@${ECHO} "Set MOINTYPE=(CGI|FCGI|WSGI|STANDALONE) to define"
	@${ECHO} "type of installation. Default is CGI."
	@${ECHO} "Use MOINDEST=/path to modify installation destination."
	@${ECHO} "Default value for MOINDEST is ${PREFIX}/www/wiki."
	@${ECHO}
	@${ECHO} "To get correct permissions, please set CGIUSER, CGIGROUP"
	@${ECHO} "per default it is set to www:www."
	@${ECHO}

instance: pre-everything apply-slist
	@${ECHO_CMD} "Creating a new wiki instance in ${MOINDEST}."; \
	if [ -f ${MOINDIR}/config/wikiconfig.py ]; then \
		${MKDIR} ${MOINDEST}; \
		${CP} -R ${MOINDIR}/data ${MOINDEST}; \
		${CP} -R ${MOINDIR}/underlay ${MOINDEST}; \
		${CHMOD} -R u+rw,go-ws ${MOINDEST}/data; \
		${INSTALL_SCRIPT} ${MOINDIR}/config/wikiconfig.py ${MOINDEST}; \
		if [ ! -z ${MOINSCRIPT} ]; then \
			${INSTALL_SCRIPT} ${MOINSCRIPT} ${MOINDEST}; \
		fi; \
		${CHOWN} -R ${CGIUSER}:${CGIGROUP} ${MOINDEST}; \
		${SH} ${PKGINSTALL} ${PKGNAME} INSTANCE ${MOINTYPE}; \
	else \
		${ECHO_CMD} "You need to install moinmoin first before trying"; \
		${ECHO_CMD} "to add a new wiki instance."; \
	fi

.include <bsd.port.mk>

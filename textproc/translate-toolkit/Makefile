# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	translate-toolkit
PORTVERSION=	3.1.1
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools and API for translation and localization engineering

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	bash:shells/bash \
		msghack:devel/gettext-msghack \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		gettext python:3.5+ shebangfix
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

SHEBANG_FILES=	tools/*

MANPAGES=	csv2po csv2tbx dtd2po flatxml2po html2po idml2po json2po moz2po mozlang2po odf2xliff oo2po oo2xliff po2csv po2dtd po2flatxml po2html po2idml po2json po2moz po2mozlang po2oo po2prop po2resx po2sub po2symb po2tiki po2tmx po2ts po2txt po2web2py po2wordfast po2xliff pot2po prop2po resx2po sub2po symb2po tbx2po tiki2po ts2po txt2po web2py2po xliff2odf xliff2oo

OPTIONS_DEFINE=	OPTIONAL
OPTIONS_DEFAULT=OPTIONAL
OPTIONS_SUB=	yes
OPTIONAL_DESC=	Optional dependencies

OPTIONAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aeidon>=1.7.0:textproc/py-aeidon@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.3:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}chardet>=3.0.4:textproc/py-chardet@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}iniparse>=0.5:devel/py-iniparse@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}phply>=1.2.5:devel/py-phply@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycountry>=20.7.3:textproc/py-pycountry@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}enchant>=3.1.1:textproc/py-enchant@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.7:devel/py-pyparsing@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-Levenshtein>=0.12:devel/py-python-Levenshtein@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}vobject>=0.9.6.1:deskutils/py-vobject@${PY_FLAVOR}
OPTIONAL_MANPAGES=	ical2po ini2po php2po po2ical po2ini po2php po2rc rc2po

post-build:
	@${MKDIR} ${WRKSRC}/manpages
.for manpage in ${MANPAGES}
	cd ${WRKSRC}/build/lib/translate/convert && ${SETENV} PYTHONPATH=${WRKSRC}/build/lib ${PYTHON_CMD} ${manpage}.py --man > ${WRKSRC}/manpages/${manpage}.1
.endfor

post-build-OPTIONAL-on:
.for manpage in ${OPTIONAL_MANPAGES}
	cd ${WRKSRC}/build/lib/translate/convert && ${SETENV} PYTHONPATH=${WRKSRC}/build/lib ${PYTHON_CMD} ${manpage}.py --man > ${WRKSRC}/manpages/${manpage}.1
.endfor

post-install:
	cd ${WRKSRC}/manpages && ${INSTALL_MAN} * ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

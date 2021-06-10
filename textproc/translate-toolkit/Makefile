# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	translate-toolkit
PORTVERSION=	3.3.6
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools and API for translation and localization engineering

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	bash:shells/bash \
		msghack:devel/gettext-msghack \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.6.3:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		gettext python:3.6+ shebangfix
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

SHEBANG_FILES=	tools/*

MANPAGES=	csv2po csv2tbx dtd2po flatxml2po html2po idml2po json2po moz2po mozlang2po odf2xliff oo2po oo2xliff po2csv po2dtd po2flatxml po2html po2idml po2json po2moz po2mozlang po2oo po2prop po2resx po2sub po2symb po2tiki po2tmx po2ts po2txt po2web2py po2wordfast po2xliff pot2po prop2po resx2po sub2po symb2po tbx2po tiki2po ts2po txt2po web2py2po xliff2odf xliff2oo

OPTIONS_DEFINE=	ENCODING ICAL INI LANGUAGES LEVENSHTEIN PHP RC SPELLCHECK SUBTITLES TMSERVER TRADOS YAML
OPTIONS_DEFAULT=ENCODING ICAL INI LANGUAGES LEVENSHTEIN PHP RC SPELLCHECK SUBTITLES TMSERVER TRADOS YAML
OPTIONS_SUB=	yes
ENCODING_DESC=	Encoding detection
ICAL_DESC=	iCal format support
INI_DESC=	INI format support
LANGUAGES_DESC=	Languages names
LEVENSHTEIN_DESC=	Faster matching using Levenshtein
PHP_DESC=	PHP format support
RC_DESC=	Windows Resource (.rc) format support
SPELLCHECK_DESC=Enchant spellchecking system
SUBTITLES_DESC=	Subtitles format support
TMSERVER_DESC=	Tmserver backend support
TRADOS_DESC=	Trados format support
YAML_DESC=	YAML format support

ENCODING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=4.0.0,1:textproc/py-chardet@${PY_FLAVOR}
ICAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vobject>=0.9.6.1:deskutils/py-vobject@${PY_FLAVOR}
ICAL_VARS=		MANPAGES+="ical2po po2ical"
INI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iniparse>=0.5:devel/py-iniparse@${PY_FLAVOR}
INI_VARS=		MANPAGES+="ini2po po2ini"
LANGUAGES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycountry>=20.7.3:textproc/py-pycountry@${PY_FLAVOR}
LEVENSHTEIN_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}python-Levenshtein>=0.12:devel/py-python-Levenshtein@${PY_FLAVOR}
PHP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phply>=1.2.5:devel/py-phply@${PY_FLAVOR}
PHP_VARS=		MANPAGES+="php2po po2php"
RC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.7:devel/py-pyparsing@${PY_FLAVOR}
RC_VARS=		MANPAGES+="po2rc rc2po"
SPELLCHECK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=3.2.0:textproc/py-enchant@${PY_FLAVOR}
SUBTITLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aeidon>=1.9:textproc/py-aeidon@${PY_FLAVOR}
TMSERVER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheroot>=8.5.2:www/py-cheroot@${PY_FLAVOR}
TRADOS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.3:www/py-beautifulsoup@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.16.12:devel/py-ruamel.yaml@${PY_FLAVOR}
YAML_VARS=		MANPAGES+="po2yaml yaml2po"

.include <bsd.port.options.mk>

post-build:
	@${MKDIR} ${WRKSRC}/manpages
.for manpage in ${MANPAGES}
	cd ${WRKSRC}/build/lib/translate/convert && ${SETENV} PYTHONPATH=${WRKSRC}/build/lib ${PYTHON_CMD} ${manpage}.py --man > ${WRKSRC}/manpages/${manpage}.1
.endfor

post-install:
	cd ${WRKSRC}/manpages && ${INSTALL_MAN} * ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

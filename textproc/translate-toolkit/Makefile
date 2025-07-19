PORTNAME=	translate-toolkit
PORTVERSION=	3.12.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	PYPI \
		https://github.com/translate/translate/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools and API for translation and localization engineering
WWW=		https://toolkit.translatehouse.org/ \
		https://github.com/translate/translate

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${RUN_DEPENDS}
RUN_DEPENDS=	bash:shells/bash \
		msghack:devel/gettext-msghack \
		${PYTHON_PKGNAMEPREFIX}lxml5>=4.6.3:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		gettext python shebangfix
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

SHEBANG_FILES=	tools/* \
		translate/convert/odfxml \
		translate/convert/roundtrip-OOo \
		translate/convert/roundtrip-gaia \
		translate/convert/roundtrip-mozilla

MANPAGES=	android2po csv2po csv2tbx dtd2po flatxml2po html2po idml2po json2po moz2po mozlang2po odf2xliff oo2po oo2xliff po2csv po2dtd po2flatxml po2html po2idml po2json po2moz po2mozlang po2oo po2prop po2resx po2sub po2symb po2tiki po2tmx po2ts po2txt po2web2py po2wordfast po2xliff pot2po prop2po resx2po sub2po symb2po tbx2po tiki2po ts2po txt2po web2py2po xliff2odf xliff2oo

OPTIONS_DEFINE=	ENCODING FLUENT ICAL INI LEVENSHTEIN MARKDOWN PHP RC SPELLCHECK SUBTITLES TMSERVER TRADOS YAML
OPTIONS_DEFAULT=ENCODING FLUENT ICAL INI LEVENSHTEIN MARKDOWN PHP RC SPELLCHECK SUBTITLES TMSERVER TRADOS YAML
OPTIONS_SUB=	yes
ENCODING_DESC=	Encoding detection
FLUENT_DESC=	Fluent translation format support
ICAL_DESC=	iCal format support
INI_DESC=	INI format support
LEVENSHTEIN_DESC=	Faster matching using Levenshtein
MARKDOWN_DESC=	Markdown format support
PHP_DESC=	PHP format support
RC_DESC=	Windows Resource (.rc) format support
SPELLCHECK_DESC=Enchant spellchecking system
SUBTITLES_DESC=	Subtitles format support
TMSERVER_DESC=	Tmserver backend support
TRADOS_DESC=	Trados format support
YAML_DESC=	YAML format support

ENCODING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.3.2:textproc/py-charset-normalizer@${PY_FLAVOR}
FLUENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fluent.syntax>=0.19.0:textproc/py-fluent.syntax@${PY_FLAVOR}
ICAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vobject>=0.9.6.1:deskutils/py-vobject@${PY_FLAVOR}
ICAL_VARS=		MANPAGES+="ical2po po2ical"
INI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iniparse>=0.5:devel/py-iniparse@${PY_FLAVOR}
INI_VARS=		MANPAGES+="ini2po po2ini"
LEVENSHTEIN_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}Levenshtein>=0.12:devel/py-Levenshtein@${PY_FLAVOR}
MARKDOWN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mistletoe>=1.3.0:textproc/py-mistletoe@${PY_FLAVOR}
MARKDOWN_VARS=		MANPAGES+="md2po po2md"
PHP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phply>=1.2.6:devel/py-phply@${PY_FLAVOR}
PHP_VARS=		MANPAGES+="php2po po2php"
RC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.0.7:devel/py-pyparsing@${PY_FLAVOR}
RC_VARS=		MANPAGES+="po2rc rc2po"
SPELLCHECK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=3.2.2:textproc/py-enchant@${PY_FLAVOR}
SUBTITLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aeidon>=1.13:textproc/py-aeidon@${PY_FLAVOR}
TMSERVER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheroot>=10.0.0:www/py-cheroot@${PY_FLAVOR}
TRADOS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.3:www/py-beautifulsoup@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.18.5:devel/py-ruamel.yaml@${PY_FLAVOR}
YAML_VARS=		MANPAGES+="po2yaml yaml2po"

.include <bsd.port.options.mk>

post-build:
	@${MKDIR} ${WRKSRC}/manpages
.for manpage in ${MANPAGES}
	cd ${WRKSRC}/build/lib/translate/convert && ${SETENVI} ${WRK_ENV} PYTHONPATH=${WRKSRC}/build/lib ${PYTHON_CMD} ${manpage}.py --man > ${WRKSRC}/manpages/${manpage}.1
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/manpages/* ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

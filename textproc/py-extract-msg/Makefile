PORTNAME=	extract-msg
DISTVERSION=	0.46.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	extract_msg-${PORTVERSION}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Extracts emails and attachments saved in MS Outlook's .msg files
WWW=		https://github.com/TeamMsgExtractor/msg-extractor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.11.1:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=4.0.0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}compressed-rtf>=1.0.6:archivers/py-compressed-rtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ebcdic>=1.1.1:textproc/py-ebcdic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imapclient>=2.1.0:mail/py-imapclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}olefile>=0.46:devel/py-olefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz-deprecation-shim>0:devel/py-pytz-deprecation-shim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}red-black-tree-mod>=0:devel/py-red-black-tree-mod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}RTFDE>=0.0.2:textproc/py-RTFDE@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=4.2:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		WKHTMLTOPDF
OPTIONS_DEFAULT=	WKHTMLTOPDF

WKHTMLTOPDF_DESC=		Enable support for converting the body as PDF

WKHTMLTOPDF_RUN_DEPENDS=	wkhtmltopdf>0:converters/wkhtmltopdf

.include <bsd.port.mk>

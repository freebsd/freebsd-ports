# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	translate-toolkit
PORTVERSION=	2.4.0
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts between many translation formats

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0:deskutils/py-vobject@${PY_FLAVOR} \
		msghack:devel/gettext-msghack \
		${PYTHON_PKGNAMEPREFIX}iniparse>=0:devel/py-iniparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-Levenshtein>=0:devel/py-python-Levenshtein@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		iso-codes>=1.3:misc/iso-codes \
		bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}utidylib>=0:www/py-utidylib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backports.csv>=1.0.0:devel/py-backports.csv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phply>=1.2.5:devel/py-phply@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
# Can use psyco (on i386)

NO_ARCH=	yes
USES=		gettext python:2.7
USE_PYTHON=	autoplist distutils

# list of manual pages to generate
GEN_MAN=	csv2po.1 csv2tbx.1 dtd2po.1 html2po.1 ical2po.1 idml2po.1 \
		ini2po.1 json2po.1 moz2po.1 mozlang2po.1 odf2xliff.1 oo2po.1 \
		oo2xliff.1 php2po.1 po2csv.1 po2dtd.1 po2html.1 po2ical.1 \
		po2idml.1 po2ini.1 po2json.1 po2moz.1 po2mozlang.1 po2oo.1 \
		po2php.1  po2prop.1 po2rc.1 po2resx.1 po2sub.1 po2symb.1 \
		po2tiki.1 po2tmx.1 po2ts.1 po2txt.1 po2web2py.1 po2wordfast.1 \
		po2xliff.1 pot2po.1 prop2po.1 rc2po.1 resx2po.1 sub2po.1 \
		symb2po.1 tbx2po.1 tiki2po.1 web2py2po.1 xliff2odf.1 xliff2oo.1

post-patch:
	@${FIND} ${WRKSRC}/tools -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!${LOCALBASE}/bin/bash| ; \
		 s|mktemp|mktemp -t /tmp|'

post-build:
	@${MKDIR} ${WRKDIR}/manpages
.for i in ${GEN_MAN:S|.1||}
	cd ${WRKSRC}/build/lib/translate/convert && \
		${SETENV} PYTHONPATH=${WRKSRC}/build/lib ${PYTHON_CMD} \
			${i}.py --man > ${WRKDIR}/manpages/${i}.1
.endfor

post-install:
.for i in ${GEN_MAN}
	cd ${WRKDIR}/manpages && ${INSTALL_MAN} ${i} ${STAGEDIR}${PREFIX}/man/man1
.endfor

list-man1:	build
	@cd ${WRKSRC}/build/scripts-* && ${GREP} -l "${PYTHON_CMD}" * | \
		${EGREP} -v '(build_tmdb|pocount|poterminology|tmserver)' | \
		${TR} "\n" " "

.include <bsd.port.mk>

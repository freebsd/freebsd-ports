# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwytter
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	net-im www python
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free multi-platform Twitter client written in Python

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.7.1:devel/py-simplejson

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		dos2unix gettext python:2 zip
USE_PYTHON=	autoplist distutils
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DOS2UNIX_GLOB=	 *.py

post-patch:
	@${RM} -rf ${WRKSRC}/twclient/simplejson
	@${REINPLACE_CMD} -e "s|'simplejson|}, #&|" \
		-e "s|pwParam|pwCache','&|" \
		-e "s|d\[p\]|d\['share/'+p\]|g" \
		-e 's|text",|${DATADIR_REL}/text",|' \
		-e 's|media",|${DATADIR_REL}/media",|' \
		-e 's|theme",|${DATADIR_REL}/theme",|' \
		-e 's|\\\\|/|' \
		-e "/import ez_setup/d" \
		-e "/ez_setup.use_setuptools()/d" ${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
		-e 's|locale_path = .*|locale_path = "${PREFIX}/share/locale"|' \
		-e '1,3d' \
		-e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/pwytter.py
	@${REINPLACE_CMD} -e 's|media"|${DATADIR}/&|' ${WRKSRC}/pwytter.py \
		${WRKSRC}/twclient/__init__.py
	@${REINPLACE_CMD} -e "s|theme'|${DATADIR}/&|" ${WRKSRC}/pwTheme.py
	@${FIND} ${WRKSRC}/locale -name pwytter.po -delete

.include <bsd.port.mk>

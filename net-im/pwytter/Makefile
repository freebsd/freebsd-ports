# New ports collection makefile for:	Pwytter
# Date created:				24 May 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pwytter
PORTVERSION=	0.8
CATEGORIES=	net-im www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A free multi-platform Twitter client written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.7.1:${PORTSDIR}/devel/py-simplejson

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_ZIP=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch: .SILENT
	${RM} -r ${WRKSRC}/twclient/simplejson
# Prefer system-wide `simplejson' module; fix for broken `setup.py': include
# `pwCache.py' in sources list, adjust locale data path
	${REINPLACE_CMD} -e "s|'simplejson|}, #&|" \
		-e "s|pwParam|pwCache','&|" ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e 's|locale_path =|& "${PYEASYINSTALL_SITELIBDIR}/${PYEASYINSTALL_EGG}/locale" #|' \
		${WRKSRC}/pwytter.py
# Adjust paths for themes and media (don't assume they are relative to .)
	${REINPLACE_CMD} -e 's|media"|${DATADIR}/&|' ${WRKSRC}/pwytter.py \
		${WRKSRC}/twclient/__init__.py
	${REINPLACE_CMD} -e "s|theme'|${DATADIR}/&|" ${WRKSRC}/pwTheme.py
# Remove gettext `.po' files: not needed when we have them precompiled
	${FIND} ${WRKSRC}/locale -name pwytter.po -delete

post-install:
# Install themes and media files where they belong
	@${MKDIR} ${DATADIR}/media ${DATADIR}/theme
	@${INSTALL_DATA} ${WRKSRC}/media/* ${DATADIR}/media
	@${INSTALL_DATA} ${WRKSRC}/theme/* ${DATADIR}/theme

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	pastebinit
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	misc python
MASTER_SITES=	https://launchpad.net/pastebinit/trunk/${PORTVERSION}/+download/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line utility for pastebing

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:devel/py-configobj

USES=		python:run shebangfix tar:bzip2
SHEBANG_FILES=	pastebinit
python_OLD_CMD=	/usr/bin/python3
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/pastebinit
PORTDATA=	*

OPTIONS_DEFINE=	PASTEBINS
OPTIONS_DEFAULT=PASTEBINS
PASTEBINS_DESC=	Install default pastebins

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/pastebin.d|${DATADIR}/pastebin.d|' \
		${WRKSRC}/pastebinit
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-PASTEBINS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pastebin.d ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

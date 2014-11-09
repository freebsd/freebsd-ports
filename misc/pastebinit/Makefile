# $FreeBSD$

PORTNAME=	pastebinit
PORTVERSION=	1.4.1
CATEGORIES=	misc python
MASTER_SITES=	https://launchpad.net/pastebinit/trunk/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line utility for pastebing

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:${PORTSDIR}/devel/py-configobj

USES=		python:run shebangfix tar:bzip2
SHEBANG_FILES=	pastebinit
python_OLD_CMD=	/usr/bin/python3
NO_BUILD=	yes

PLIST_FILES=	bin/pastebinit

OPTIONS_DEFINE=	PASTEBINS
PASTEBINS_DESC=	Install default pastebins
OPTIONS_DEFAULT=	PASTEBINS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPASTEBINS}
PORTDATA=	pastebin.d
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/share/pastebin.d|${DATADIR}/pastebin.d|' \
		${WRKSRC}/pastebinit
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MPASTEBINS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pastebin.d ${STAGEDIR}${DATADIR})
.endif

.include <bsd.port.mk>

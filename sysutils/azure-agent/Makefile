# $FreeBSD$

PORTNAME=	azure-agent
PORTVERSION=	${GH_TAGNAME}.11
CATEGORIES=	sysutils

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	The Microsoft Azure Linux Agent

LICENSE=	APACHE20

RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		sudo:${PORTSDIR}/security/sudo \
		bash:${PORTSDIR}/shells/bash \
		${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

NO_BUILD=	yes
USES=		python:2

USE_GITHUB=	yes
GH_ACCOUNT=	Azure
GH_PROJECT=	WALinuxAgent
GH_TAGNAME=	2.0

PLIST_FILES=	sbin/waagent

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/waagent ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>

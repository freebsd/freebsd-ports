PORTNAME=	ansible-sshjail
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0-30
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g981674f
CATEGORIES=	sysutils

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ansible connector for remote jails

LICENSE=	MIT

USES=		ansible:plugin python
ANSIBLE_PLUGIN_TYPE=	connection
USE_GITHUB=	yes

GH_ACCOUNT=	austinhyde

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${ANSIBLE_PLUGINSDIR}/sshjail.py

do-install:
	${MKDIR} ${STAGEDIR}/${ANSIBLE_PLUGINSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sshjail.py \
		${STAGEDIR}/${ANSIBLE_PLUGINSDIR}/sshjail.py

.include <bsd.port.mk>

# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	radicale
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Radicale-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python based CalDAV/CardDAV server

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>=1.6.5:security/py-passlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

USERS=		radicale
GROUPS=		radicale
USE_RC_SUBR=	radicale
SUB_LIST=	PYTHON_CMD="${PYTHON_CMD}" \
		PYTHON_VER="${PYTHON_VER}"

OPTIONS_DEFINE=	HTTP LDAP
HTTP_DESC=	HTTP authentication support

HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests1>=0:www/py-requests1@${PY_FLAVOR}
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=0:net/py-ldap@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} 's|~/.config/radicale|${DATADIR}|; s|/etc|${PREFIX}/etc|' ${WRKSRC}/config

post-install:
	@${MKDIR} ${STAGEDIR}/${ETCDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}/${ETCDIR}/config.sample
	${INSTALL_DATA} ${WRKSRC}/logging ${STAGEDIR}/${ETCDIR}/logging.sample

.include <bsd.port.mk>

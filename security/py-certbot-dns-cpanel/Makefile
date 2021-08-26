PORTNAME=	certbot-dns-cpanel
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	h.freshports@skarnell.se
COMMENT=	CPanel DNS Authenticator plugin for Certbot

LICENSE=	APACHE20

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}certbot>0:security/py-certbot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	"${PREFIX}/etc/certbot-dns-cpanel/credentials.ini.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/certbot-dns-cpanel
	${INSTALL_DATA} ${FILESDIR}/credentials.ini.sample \
		${STAGEDIR}${PREFIX}/etc/certbot-dns-cpanel

.include <bsd.port.mk>

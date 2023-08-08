PORTNAME=	wsdd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	Web Service Discovery (WSD) host daemon for Samba
WWW=		https://github.com/christgau/wsdd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	christgau
SHEBANG_FILES=	src/${PORTNAME}.py
NO_ARCH=	yes
NO_BUILD=	yes

USERS=		_wsdd
GROUPS=		_wsdd

PLIST_FILES=	bin/${PORTNAME} \
		etc/rc.d/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

post-patch:
	${REINPLACE_CMD} 's|PYTHON|${PYTHON_CMD}|' ${WRKSRC}/etc/rc.d/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/${PORTNAME}.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/etc/rc.d/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8 \
		${STAGEDIR}${MANPREFIX}/man/man8/

.include <bsd.port.mk>

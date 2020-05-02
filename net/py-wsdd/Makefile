# $FreeBSD$

PORTNAME=	wsdd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hiroo.ono+freebsd@gmail.com
COMMENT=	Web Service Discovery (WSD) host daemon for Samba

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		python:3.5+,run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	christgau
SHEBANG_FILES=	src/${PORTNAME}.py
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		etc/rc.d/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/${PORTNAME}.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/etc/rc.d/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>

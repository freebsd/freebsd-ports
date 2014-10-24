# Created by: Jesse Kempf <jessekempf@gmail.com>
# $FreeBSD$

PORTNAME=	sievelog
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Syslog message filter

USES=		python
USE_PYTHON=	distutils

SUB_FILES=	pkg-message

post-install:
	@${CP} -p ${WRKSRC}/test.sv ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.example
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/man/man5/${PORTNAME}.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>

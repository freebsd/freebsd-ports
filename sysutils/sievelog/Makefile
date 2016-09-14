# Created by: Jesse Kempf <jessekempf@gmail.com>
# $FreeBSD$

PORTNAME=	sievelog
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Syslog message filter

BROKEN=		Unfetchable (google code has gone away)

USES=		python
USE_PYTHON=	distutils

SUB_FILES=	pkg-message

post-install:
	@${CP} -p ${WRKSRC}/test.sv ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/man/man5/${PORTNAME}.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5

.include <bsd.port.mk>

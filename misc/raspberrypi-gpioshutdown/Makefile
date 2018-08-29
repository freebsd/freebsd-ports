# $FreeBSD$

PORTNAME=	raspberrypi-gpioshutdown
DISTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://mrp3.com/

MAINTAINER=	bobf@mrp3.com
COMMENT=	Kernel driver to reset GPIO pins on shutdown for Raspberry Pi

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	armv6 armv7

KMODNAME=	gpioshutdown
USES=		kmod
USE_RC_SUBR=	${KMODNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_KLD} ${WRKSRC}/${KMODNAME}.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/gpioshutdown.4 ${STAGEDIR}${PREFIX}/man/man4/

.include <bsd.port.mk>

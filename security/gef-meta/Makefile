PORTNAME=	gef
PORTVERSION=	${GEF_VERSION}
PORTREVISION=	0
CATEGORIES=	security

MAINTAINER=	zyj20@cl.cam.ac.uk
COMMENT=	Meta-port for the default version of the GDB Enhanced Features for exploit devs & reversers
WWW=		https://github.com/CTSRD-CHERI/gef
DESCR=		${.CURDIR}/../gef/pkg-descr

USES=		metaport

RUN_DEPENDS=	${LOCALBASE}/share/gef-cheri/gef.py:security/gef-cheri

.include "${.CURDIR}/../gef-cheri/Makefile.snapshot"
.include <bsd.port.mk>

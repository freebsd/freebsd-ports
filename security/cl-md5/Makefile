# $FreeBSD$

PORTNAME=	md5
PORTVERSION=	1.8.5
PORTREVISION=	1
CATEGORIES=	security lisp
MASTER_SITES=	http://ftp.de.debian.org/debian/pool/main/c/cl-md5/
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}.orig
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A native MD5 implementation in Common Lisp

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${DISTVERSION}
NO_BUILD=	yes

USE_ASDF=	yes

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.asd ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>

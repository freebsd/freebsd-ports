# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	getdp
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.geuz.org/getdp/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Rather general finite element solver using mixed finite elements

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/README.txt

LIB_DEPENDS=	libgsl.so:math/gsl	\
		liblapack.so:math/lapack

USES=		fortran gmake tar:tgz cmake
WANT_PERL=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if defined(MAINTAINER_MODE)
regression-test:	install
	cd ${WRKSRC}/demos && yes "" | ${PORTNAME} magnet.pro -solve MagSta_phi
.endif

.include <bsd.port.post.mk>

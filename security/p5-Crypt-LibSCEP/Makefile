# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	Crypt-LibSCEP
DISTVERSIONPREFIX=	v
PORTVERSION=	0.06
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Easy-to-use interface between LibSCEP and Perl programs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/Readme.md

BUILD_DEPENDS=	libscep>=0.06:security/libscep
RUN_DEPENDS=	libscep>=0.06:security/libscep

USES=		gmake perl5 ssl
USE_PERL5=	configure
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
GH_PROJECT=	libscep

WRKSRC_SUBDIR=	src/clients/perl/${PORTNAME}
DOTNAME=	${PORTNAME:S|-|.|g}
NAME1=	${DOTNAME:R}
NAME2=	${DOTNAME:E}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/${NAME1}/${NAME2}/${NAME2}.so

.include <bsd.port.mk>

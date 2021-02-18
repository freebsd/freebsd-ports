# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	Crypt-LibSCEP
PORTVERSION=	0.08
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Easy-to-use interface between LibSCEP and Perl programs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/Readme.md

BUILD_DEPENDS=	libscep>=0.08:security/libscep
RUN_DEPENDS=	libscep>=0.08:security/libscep

USES=		gmake localbase perl5 ssl
USE_GITHUB=	yes
GH_ACCOUNT=	openxpki
GH_PROJECT=	libscep
USE_PERL5=	configure

WRKSRC_SUBDIR=	src/clients/perl/${PORTNAME}
_DOTNAME=	${PORTNAME:S|-|.|g}
_NAME1=		${_DOTNAME:R}
_NAME2=		${_DOTNAME:E}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/${_NAME1}/${_NAME2}/${_NAME2}.so

.include <bsd.port.mk>

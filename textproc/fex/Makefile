# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fex
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Powerful field extraction tool

LICENSE=	APACHE20

USES=		perl5
USE_PERL5=	build # pod2man
USE_GITHUB=	yes
GH_ACCOUNT=	jordansissel

MAKE_ENV+=	INSTALLMAN=${PREFIX}/man

PLIST_FILES=	bin/fex man/man1/fex.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

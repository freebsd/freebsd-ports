# $FreeBSD$

PORTNAME=	irrtoolset
DISTVERSIONPREFIX=	release-
DISTVERSION=	5.1.3
CATEGORIES=	net-mgmt

MAINTAINER=	rkoberman@gmail.com
COMMENT=	Suite of routing policy tools to interact with the IRR

LICENSE=	MIT GPLv2+ RIPE_NCC
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf bison gmake libtool
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	irrtoolset
GH_PROJECT=	irrtoolset

PLIST_FILES=	bin/rpslcheck bin/peval bin/rtconfig \
		man/man1/rtconfig.1.gz man/man1/peval.1.gz \
		man/man1/rpslcheck.1.gz man/man1/irrtoolset-errors.1.gz

.include <bsd.port.mk>

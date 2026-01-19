PORTNAME=	himitsu
DISTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	para@dismail.de
COMMENT=	Secret storage system for Unix systems
WWW=		https://himitsustore.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hare:devel/hare \
		scdoc:textproc/scdoc
TEST_DEPENDS=	hare:devel/hare

TEST_TARGET=	check

.include <bsd.port.mk>

PORTNAME=	mmv
DISTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/rrthomas/mmv/releases/download/v${DISTVERSION}/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Move/Copy/Append/Link multiple files
WWW=		https://github.com/rrthomas/mmv

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man

USES=		gmake

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

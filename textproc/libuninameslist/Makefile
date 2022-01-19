# Created by: KANOU Hiroki <kanou@khdd.net>

PORTNAME=	libuninameslist
DISTVERSION=	20211114
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/fontforge/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-dist-${DISTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Library of Unicode annotation data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	FRENCH
OPTIONS_DEFAULT=FRENCH
OPTIONS_SUB=yes

FRENCH_DESC=	Build French library
FRENCH_CONFIGURE_ENABLE=	frenchlib

.include <bsd.port.mk>

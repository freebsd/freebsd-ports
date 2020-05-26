# $FreeBSD$

PORTNAME=	fastjet
DISTVERSION=	3.3.4
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://fastjet.fr/repo/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for jet finding in pp and e+e- collisions

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		fortran gmake libtool shebangfix
SHEBANG_FILES=	fastjet-config.in
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-allplugins

LDFLAGS+=	-lexecinfo

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>

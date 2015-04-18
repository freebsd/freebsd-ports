# Created by: ijliao
# $FreeBSD$

PORTNAME=	spar
PORTVERSION=	0.5.10
PORTREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	SF/${PORTNAME}/Spar/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular math parser

USES=		libtool readline
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-ldl,,g" \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/lib/module/Makefile.in

.include <bsd.port.mk>

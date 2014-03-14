# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pvm++
PORTVERSION=	0.6.0
PORTREVISION=	5
CATEGORIES=	net parallel
MASTER_SITES=	SF/pvm-plus-plus/pvm-plus-plus/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++-Library for PVM

BUILD_DEPENDS=	${LOCALBASE}/lib/libpvm3.a:${PORTSDIR}/net/pvm

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=		gmake
USE_AUTOTOOLS=	libtool
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pvm-incs=${LOCALBASE}/include \
		--with-pvm-libs=${LOCALBASE}/lib
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>

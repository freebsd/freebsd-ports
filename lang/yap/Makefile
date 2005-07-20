# ex:ts=8
# New ports collection makefile for:	yap
# Date created:			Apr 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yap
PORTVERSION=	4.5.6
CATEGORIES=	lang
MASTER_SITES=	http://www.ncc.up.pt/~vsc/Yap/Yap4.5/
DISTNAME=	Yap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance Prolog compiler

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		yap

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

post-extract:
	@${RM} -f ${WRKSRC}/docs/*.info*

post-build:
	cd ${WRKSRC}/docs && makeinfo --no-split yap.tex

pre-install:
	@${MKDIR} ${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/docs/yap.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>

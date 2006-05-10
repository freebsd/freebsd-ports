# ex:ts=8
# New ports collection makefile for:	yap
# Date created:			Apr 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yap
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.ncc.up.pt/~vsc/Yap/%SUBDIR%/
MASTER_SITE_SUBDIR=	Yap-${PORTVERSION}
DISTNAME=	Yap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance Prolog compiler

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		yap

.include <bsd.port.pre.mk>

post-extract:
	@${RM} -f ${WRKSRC}/docs/*.info*

post-patch:
	@${REINPLACE_CMD} -e 's|VERSION}|VERSION:}|g' ${WRKSRC}/docs/yap.tex

post-build:
	cd ${WRKSRC}/docs && makeinfo --no-split yap.tex

pre-install:
	@${MKDIR} ${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/docs/yap.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>

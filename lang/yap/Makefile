# ex:ts=8
# New ports collection makefile for:	yap
# Date created:			Apr 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yap
PORTVERSION=	4.4.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Yap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance Prolog compiler

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		yap

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/docs/*.info*

post-build:
	cd ${WRKSRC}/docs && makeinfo --no-split yap.tex

pre-install:
	${INSTALL_DATA} ${WRKSRC}/docs/yap.info ${PREFIX}/info
	install-info ${PREFIX}/info/yap.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>

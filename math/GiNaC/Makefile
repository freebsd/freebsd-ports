# ex:ts=8
# New ports collection makefile for:	GiNaC
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GiNaC
PORTVERSION=	1.0.12
PORTREVISION=	0
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A C++ library for symbolic mathematical calculations

LIB_DEPENDS=	cln.2:${PORTSDIR}/math/cln

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"
INSTALLS_SHLIB=	yes

MAN1=	ginac-config.1 ginsh.1 viewgar.1

post-extract:
	@${RM} -f ${WRKSRC}/doc/tutorial/ginac.info*

post-patch:
.for file in configure ginac/numeric.cpp ginac/tostring.h
	@${REINPLACE_CMD} -e 's|sstream|strstream|g ; \
		 s|stringstream|strstream|g' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|-release \$$(LT_RELEASE)||g' \
		${WRKSRC}/ginac/Makefile.in

.include <bsd.port.mk>

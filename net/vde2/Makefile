# Created by: Philip M. Gollucci <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vde2
PORTVERSION=	2.3.2
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/vde/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libpcap.so.1:net/libpcap

USES=		gmake libtool pathfix shebangfix ssl
USE_LDCONFIG=	yes

CONFLICTS=	vde-[0-9]*
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	src/lib/python/VdePlug.py
MAKE_ENV=	V=1
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=	PYTHON

OPTIONS_SUB=	yes
PYTHON_CONFIGURE_OFF=	--disable-python
PYTHON_USES=	python gettext-runtime
PYTHON_CPPFLAGS=	-I${LOCALBASE}/include
PYTHON_LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/-Wall/s|-O2||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(MAKE).*install-data-hook||g' \
		${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|#AM_CFLAGS|g' \
		${WRKSRC}/src/slirpvde/Makefile.in

post-install:
	${LN} -sf unixcmd.1 ${STAGEDIR}${PREFIX}/man/man1/vdecmd.1
	${LN} -sf vdeq.1 ${STAGEDIR}${PREFIX}/man/man1/vdeqemu.1
	${LN} -sf vdeq.1 ${STAGEDIR}${PREFIX}/man/man1/vdekvm.1

.include <bsd.port.mk>

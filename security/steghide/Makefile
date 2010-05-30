# New ports collection makefile for:	steghide
# Date created:				26 February 2001
# Whom:					RaRa Rasputin <rasputin@submonkey.net>
#
# $FreeBSD$
#

PORTNAME=	steghide
PORTVERSION=	0.5.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Steganography tool to hide data in binary files

LIB_DEPENDS=	mcrypt.8:${PORTSDIR}/security/libmcrypt \
		mhash.2:${PORTSDIR}/security/mhash

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GETTEXT=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include -fpermissive" \
		LIBS="-L${LOCALBASE}/lib -lintl -lmcrypt"

MAN1=		steghide.1

post-patch:
.ifdef(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|install-data-am\: install-docDATA||' \
		${WRKSRC}/Makefile.in
.endif
	${REINPLACE_CMD} -e 's,SHELL) libtool,SHELL) ${LIBTOOL} --tag=CXX,' \
		${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} -e 's,-O2,${CFLAGS},' ${WRKSRC}/configure

.include <bsd.port.mk>

# New ports collection makefile for:	easysoap
# Date created:			21th September 2001
# Whom:				Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#
# $FreeBSD$
#

PORTNAME=	easysoap
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	EasySoap++-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ SOAP Library based on expat

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000 && ${ARCH} == "amd64"
BROKEN=		does not compile on FreeBSD/amd64 6.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	    ${WRKSRC}/configure

post-install:
	@${RM} -f ${PREFIX}/lib/libeasysoap.la

.include <bsd.port.post.mk>

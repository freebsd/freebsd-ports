# New ports collection makefile for:    licq
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman & Matt Heckaman
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
CATEGORIES=	net
.if defined(WITH_SOCKS)
PKGNAMESUFFIX=	-socks
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A popular ICQ-compatible plugin-based program

.if defined(WITH_SOCKS)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}
LICQ_PORT?=	${.CURDIR}

# workaround for installed autoconf/automake
CONFIGURE_ARGS+=--program-transform-name=s,y,y,

.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=--enable-socks5
CONFIGURE_ARGS+=--with-socks5-inc=${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
.endif

pre-configure:
	@${MV} ${WRKSRC}/src/licq.conf.h ${WRKSRC}/src/licq.conf.h.sed
	${SED} -e "s=/usr/share/licq=${PREFIX}/share/licq=" \
		${WRKSRC}/src/licq.conf.h.sed > ${WRKSRC}/src/licq.conf.h
	@${ECHO_MSG} Ignoring existing libgnugetopt
	@${MV} ${WRKSRC}/configure ${WRKSRC}/configure.sed
	${SED} -e "s=getopt.h==" \
		${WRKSRC}/configure.sed > ${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/security/openssl/bsd.openssl.mk"
CONFIGURE_ARGS+=--with-openssl-inc=${OPENSSLINC}
CONFIGURE_ARGS+=--with-openssl-lib=${OPENSSLLIB}

.include "${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>

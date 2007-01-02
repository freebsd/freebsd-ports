# New ports collection makefile for:	linuxdcpp
# Date created:				19 June 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linuxdcpp
PORTVERSION=	0.0.1.20070101	#0.0.1.YYYYMMDD
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~mezz/distfiles/
MASTER_SITE_SUBDIR=mezz

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A port of the win32 DC++ direct connect client to POSIX-like systems

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GNOME=	libglade2
USE_SCONS=	yes
USE_OPENSSL=	yes

.if defined(WITH_DEBUG)
SCONS_ARGS=	debug=1
STRIP=
.else
SCONS_ARGS=	release=1
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not compile on FreeBSD 4.x, due to lack of wide character in libc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; s|%%CXX%%|${CXX}|g ; \
		s|%%CXXFLAGS%%|${CXXFLAGS}|g' ${WRKSRC}/SConstruct

.include <bsd.port.post.mk>

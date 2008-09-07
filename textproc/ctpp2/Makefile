# New ports collection makefile for:   ctpp2
# Date created:         25 Jan 2008
# Whom:                 reki@reki.ru (Andrei V. Shetuhin)
#
# $FreeBSD$
#

PORTNAME=	ctpp2
PORTVERSION=	2.3.5
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://ctpp.havoc.ru/download/ \
		LOCAL/glarkin

MAINTAINER=	reki@reki.ru
COMMENT=	C++ library to use templates in C/C++ projects, version 2

USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes

.include <bsd.port.pre.mk>

# Let me explain - GCC 3.4 does not support -mtune=generic, so
# TUNE_PARAM is set to the platform-specific value.  If the platform
# is not i386 nor amd64, just disable -mtune altogether.
#
# If the system GCC 4.2+, simply use -mtune=generic for i386 and
# amd64.  Once again, disable -mtune for other platforms.
.if ${OSVERSION} < 700042
.  if ${ARCH} == "i386"
TUNE_PARAM=i686
HASHMARK=
.  elif ${ARCH} == "amd64"
TUNE_PARAM=athlon64
HASHMARK=
.  else
TUNE_PARAM=
HASHMARK=\#
.  endif
.else
.  if ${ARCH} == "i386" || ${ARCH} == "amd64"
TUNE_PARAM=generic
HASHMARK=
.  else
TUNE_PARAM=
HASHMARK=\#
.  endif
.endif

#
# This is not ideal, but because of the way CMakeLists.txt is structured,
# I have to apply a 2nd patch if -mtune is not used at all (non-i386 and
# non-amd64 arch).
#
.if ${TUNE_PARAM} == ""
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-CMakeLists.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%TUNE_PARAM%%,${TUNE_PARAM},' \
		-e 's,%%HASHMARK%%,${HASHMARK},' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>

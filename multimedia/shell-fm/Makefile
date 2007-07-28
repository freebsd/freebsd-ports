# New ports collection makefile for: shell-fm
# Date created:	15 December 2006
# Whom:		Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	shell-fm
PORTVERSION=	20061229
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://ntarmos.dyndns.org/Software/FreeBSD/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	A command-line client for Last.FM

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao \
		mad:${PORTSDIR}/audio/libmad

USE_AUTOTOOLS=	aclocal:19 automake:19 autoheader:259 autoconf:259
AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I m4
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GCC=	3.4+

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

post-install:
	@(${MKDIR} ${PREFIX}/share/examples/shell-fm && \
	${INSTALL} -m 444 ${WRKSRC}/src/shell-fm.rc-example \
		${PREFIX}/share/examples/shell-fm)

MAN1=		shell-fm.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/shell-fm \
		share/examples/shell-fm/shell-fm.rc-example
PLIST_DIRS=	share/examples/shell-fm

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>

# ex:ts=8
# Ports collection makefile for:  bro
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	bro
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.ee.lbl.gov/
DISTNAME=	${PORTNAME}-pub-${PORTVERSION}a37

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System for detecting Network Intruders in real-time

WRKSRC=		${WRKDIR}/${PORTNAME}-pub-${PORTVERSION}a37

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	CC="${CC}" CFLAGS="${CFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
USE_BISON=	yes
USE_PERL5=	yes

post-extract:
	@(cd ${WRKSRC} && ${TAR} xfvz libedit.src.tar.gz > /dev/null)

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS+=-g -O0||g; \
		s|CC=gcc||' \
		${WRKSRC}/libedit/Makefile.in \
		${WRKSRC}/libedit/Makefile

pre-configure:
	@${ECHO_CMD} "Configure libedit..."
	@(cd ${WRKSRC}/libedit && ${MAKE_ENV} ./configure)

pre-build:
	@${ECHO_CMD} "Building libedit..."
	@(cd ${WRKSRC}/libedit && ${MAKE})

pre-install:
	@${MKDIR} ${DATADIR}

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/bro
	@${INSTALL_DATA} ${WRKSRC}/policy/*.* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/bro-CN99.ps ${DOCSDIR}
	@${GZIP_CMD} ${DOCSDIR}/bro-CN99.ps
.endif

.include <bsd.port.mk>

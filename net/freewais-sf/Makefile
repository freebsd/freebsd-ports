# New ports collection makefile for:	FreeWAIS-sf
# Date created:		19 November 1996
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	freewais-sf
PORTVERSION=	2.2.14
PORTREVISION=	1
CATEGORIES=	net databases
MASTER_SITES=	ftp://ls6-ftp.cs.uni-dortmund.de/pub/src/freeWAIS-sf/
DISTNAME=	freeWAIS-sf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An enhanced Wide Area Information Server

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=	PREFIX="${PREFIX}" CC="${CC}" CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	-sde -Dprefix="${PREFIX}" \
		-Darchname="${MACHINE_ARCH}-freebsd"
INSTALL_TARGET=	install install.man

MAN1=	catalog.1 dictionary.1 inverted_file.1 mkfmt.1 waisindex.1 \
	waisq.1 waissearch.1 waisserver.1 xwais.1 xwaisq.1
MAN3=	ftw.3 regexp.3 scandir.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

post-extract:
	${CP} ${FILESDIR}/freebsd.sh ${WRKSRC}/hints

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SF
	${INSTALL_DATA} ${WRKSRC}/doc/SF/fwsf.ps ${PREFIX}/share/doc/SF
.endif

.include <bsd.port.post.mk>

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
MASTER_SITES=	ftp://ftp.ntua.gr/pub/net/freewais/ \
		http://fresh.t-systems-sfr.com/unix/src/www/ \
		http://ftp.ntua.gr/pub/net/freewais/
DISTNAME=	freeWAIS-sf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An enhanced Wide Area Information Server

HAS_CONFIGURE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ENV=	PREFIX="${PREFIX}" CC="${CC}" CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	-sde -Dprefix="${PREFIX}" \
		-Darchname="${MACHINE_ARCH}-freebsd"
INSTALL_TARGET=	install install.man

PORTDOCS=	fwsf.ps
MAN1=	catalog.1 dictionary.1 inverted_file.1 mkfmt.1 waisindex.1 \
	waisq.1 waissearch.1 waisserver.1 xwais.1 xwaisq.1
MAN3=	ftw.3 regexp.3 scandir.3

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${FILESDIR}/freebsd.sh ${WRKSRC}/hints

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/SF/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

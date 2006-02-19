# New ports collection makefile for:	colordiff
# Date created:				6 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	colordiff
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A tool to colorize diff output

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		colordiff.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/bin/perl|${PERL}|; s|/etc|${PREFIX}/etc|' \
			${WRKSRC}/${PORTNAME}.pl \
			${WRKSRC}/${MAN1}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${PREFIX}/etc/colordiffrc.default
.if !exists(${PREFIX}/etc/colordiffrc)
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${PREFIX}/etc
.endif

.include <bsd.port.post.mk>

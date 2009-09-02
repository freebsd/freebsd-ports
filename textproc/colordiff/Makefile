# New ports collection makefile for:	colordiff
# Date created:				6 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	colordiff
PORTVERSION=	1.0.8
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/version%20${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A tool to colorize diff output

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		colordiff.1

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

.include <bsd.port.mk>

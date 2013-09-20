# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	ssspl
PORTVERSION=	0.1
CATEGORIES=	net perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/sss.pl%20v${PORTVERSION}/
DISTNAME=	sss
EXTRACT_SUFX=	.pl

MAINTAINER=	gaod@hychen.org
COMMENT=	A Simple Socks Server for Perl

RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes

PLIST_FILES=	sbin/sss.pl
STRIP=

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${CHMOD} +x ${WRKSRC}/${DISTFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTFILES} ${PREFIX}/sbin

.include <bsd.port.mk>

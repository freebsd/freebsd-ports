# New ports collection makefile for:	vicq
# Date created:				06 December 2001
# Whom:					Kevin Lo<kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vicq
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	http://gonzo.kiev.ua/projects/vicq/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A text-based ICQ implementation


RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu

WRKSRC=		${WRKDIR}/${PORTNAME}

PERL_CONFIGURE=	yes


post-extract:
	${MV} ${WRKSRC}/Net/vICQ/*  ${WRKSRC}
	${RM} ${WRKSRC}/install.pl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vicq ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include <bsd.port.mk>

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


RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu

WRKSRC=		${WRKDIR}/${PORTNAME}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-extract:
	${MV} ${WRKSRC}/Net/vICQ/*  ${WRKSRC}
	${RM} ${WRKSRC}/install.pl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vicq ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include <bsd.port.mk>

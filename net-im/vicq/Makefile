# Created by: Kevin Lo<kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vicq
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://gonzo.kiev.ua/projects/vicq.old/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A text-based ICQ implementation


RUN_DEPENDS=	p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5
USE_PERL5=	configure

SIGNAL_PATCH=p5.8-patch-sigalrm

post-extract:
	${MV} ${WRKSRC}/Net/vICQ/*  ${WRKSRC}
	${RM} ${WRKSRC}/install.pl

post-patch:
	@${ECHO_MSG} "===>  Applying patch ${SIGNAL_PATCH} for ${PKGNAME}"
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/${SIGNAL_PATCH}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vicq ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/examples/vicq
	${INSTALL_DATA} ${WRKSRC}/vicqrc.example ${PREFIX}/share/examples/vicq

.include <bsd.port.mk>

# New ports collection makefile for:	bgrab
# Date created:		20 March 2000
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	bgrab
PORTVERSION=	1.3.4
CATEGORIES=	news
MASTER_SITES=	http://www.student.dtu.dk/~c960941/bgrab/

MAINTAINER=	kbyanc@posi.net

RUN_DEPENDS=	mmencode:${PORTSDIR}/converters/mmencode

post-extract:
	@${CP} ${FILESDIR}/Makefile.dist ${WRKSRC}/Makefile

.include <bsd.port.mk>

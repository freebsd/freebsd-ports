# ex:ts=8
# New ports collection makefile for:	pfinger
# Date created:			Apr 25, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pfinger
PORTVERSION=	0.7.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.xelia.ch/pub/unix/ \
		http://www.xelia.ch/unix/pfinger/

MAINTAINER=	ijliao@FreeBSD.org

USE_GTK=	yes
GNU_CONFIGURE=	yes

MAN1=	finger.1 pfinger.1
MAN5=	fingerconf.5
MAN8=	in.fingerd.8

post-patch:
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/src/configfile.c

.include <bsd.port.mk>

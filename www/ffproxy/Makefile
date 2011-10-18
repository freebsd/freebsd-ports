# New ports collection makefile for: 	ffproxy
# Date created:				Jul 20 2003
# Whom:                			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	ffproxy
PORTVERSION=	1.6
CATEGORIES=	www
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/${PORTNAME}/ \
		http://www.sourcefiles.org/System/Daemons/Proxy/ \
		http://www.nevm.de/${PORTNAME}/ \
		http://faith.eu.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filtering HTTP proxy server

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN5=	${PORTNAME}.conf.5
MAN7=	${PORTNAME}.quick.7
MAN8=	${PORTNAME}.8

post-install:
	@[ -f ${PREFIX}/etc/ffproxy.conf ] || \
	${CP} ${PREFIX}/etc/ffproxy.conf.sample ${PREFIX}/etc/ffproxy.conf

.include <bsd.port.mk>

# New ports collection makefile for:	xbms
# Date created:				Thu Dec 19 23:38:50 CET 2002
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	xbms
PORTVERSION=	0.30.6
CATEGORIES=	net
MASTER_SITES=	http://wipux2.wifo.uni-mannheim.de/~ck/
DISTNAME=       ${PORTNAME}_${PORTVERSION}

MAINTAINER=	king@v2project.com
COMMENT=	Xbms, the unix streaming server for xbox mediaplayer

ONLY_FOR_ARCHS=	i386 alpha
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|@@PREFIX@@|${PREFIX}|g' ${WRKSRC}/server.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xbms ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xbms.conf ${PREFIX}/etc/xbms.conf.sample
	${INSTALL_DATA} ${FILESDIR}/xbms.sh.sample ${PREFIX}/etc/rc.d/xbms.sh.sample

.include <bsd.port.mk>

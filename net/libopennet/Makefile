# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	libopennet
PORTVERSION=	0.9.9
CATEGORIES=	net
MASTER_SITES=	http://www.rkeene.org/files/oss/libopennet/ \
		http://www.cs.nctu.edu.tw/~gslin/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for opening files over a network

GNU_CONFIGURE=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN3=		fopen_net.3 \
		fseek_net.3 \
		lseek_net.3 \
		open_net.3 \
		opennet.3 \
		read_net.3

NO_STAGE=	yes
.include <bsd.port.mk>

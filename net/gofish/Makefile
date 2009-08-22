# ex:ts=8
# Ports collection makefile for:	gofish
# Date created:			Apr 1, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gofish
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	kaiw27@gmail.com
COMMENT=	GoFish Gopher Server

WRKSRC=		${WRKDIR}/${PORTNAME}
GOPHERROOT?=	${PREFIX}/gopher
GOPHERUSER?=	nobody
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gopherroot=${GOPHERROOT} \
		--with-gopheruser=${GOPHERUSER}
MAKE_ENV=	localstatedir=/var

MAN1=		gofish.1 mkcache.1
MAN5=		dotcache.5 gofish.5
MLINKS=		gofish.1 gopherd.1

.include <bsd.port.pre.mk>

post-install:
.for i in ${PREFIX}/etc/gofish.conf ${PREFIX}/etc/gofish-www.conf
	if test -f ${i}.new; then \
		${MV} ${i}.new ${i}.sample; \
	else \
		${CP} -p ${i} ${i}.sample; \
	fi
.endfor

.include <bsd.port.post.mk>

PORTNAME=	gofish
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	kaiw27@gmail.com
COMMENT=	GoFish Gopher Server
WWW=		https://gofish.sourceforge.net/

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}
GOPHERROOT?=	${PREFIX}/gopher
GOPHERUSER?=	nobody
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-gopherroot=${GOPHERROOT} \
		--with-gopheruser=${GOPHERUSER}
MAKE_ENV=	localstatedir=/var

post-patch:
	${REINPLACE_CMD} -e '/$$(sysconfdir)\/gofish/s|.conf|.conf.sample|3' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	libnss-mysql
PORTVERSION=	1.5
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	vd@FreeBSD.org
COMMENT=	NSS module using a MySQL database for backend

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
INSTALL_TARGET=	install-strip
USES=		libtool mysql
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} 's,$${srcdir}/aux/mkinstalldirs,$${mkinstalldirs},' \
		${WRKSRC}/Makefile.in

post-install:
.for f in libnss-mysql.cfg libnss-mysql-root.cfg
	${MV} ${STAGEDIR}${PREFIX}/etc/$f ${STAGEDIR}${PREFIX}/etc/$f.sample
.endfor

.include <bsd.port.mk>

# Created by: Adrian Wontroba <aw1@stade.co.uk>
# $FreeBSD$

PORTNAME=	xlogmaster
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick & easy monitoring of logfiles and devices

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

USE_GNOME=	gtk12
USES=		gmake makeinfo
GNU_CONFIGURE=	yes

INFO=		xlogmaster

CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} -E \
	'/(SHELL|cp -f|mkinstalldirs)/ s,XLM_(DB|HOME|LIB),DESTDIR)$$(&,g' {} \;
	@${REINPLACE_CMD} -e \
		's|getopt_long_only|getopt_long|g' ${WRKSRC}/src/xlogmaster.cc

post-install:
	${INSTALL_DATA} ${FILESDIR}/xlogmasterrc \
		${STAGEDIR}${PREFIX}/etc/xlogmaster

.include <bsd.port.mk>

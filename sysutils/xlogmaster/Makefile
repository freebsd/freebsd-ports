# Created by: Adrian Wontroba <aw1@stade.co.uk>
# $FreeBSD$

PORTNAME=	xlogmaster
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick & easy monitoring of logfiles and devices

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

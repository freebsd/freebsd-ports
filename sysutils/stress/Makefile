PORTNAME=	stress
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://repository.timesys.com/buildsources/s/stress/stress-${PORTVERSION}/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Tool to impose load on and stress test Unix-like systems

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INFO=		stress
PLIST_FILES=	bin/stress share/man/man1/stress.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CFLAGS\ \)=|\1 +=|; s|^\(CFLAGS.*\)-Wall|\1|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

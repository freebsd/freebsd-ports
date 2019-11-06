# Created by: Konrad Heuer
# $FreeBSD$

PORTNAME=	rprint
PORTVERSION=	3.2
CATEGORIES=	print
MASTER_SITES=	ftp://gwdu111.gwdg.de/pub/FreeBSD/misc/ \
		ftp://gwdu112.gwdg.de/pub/FreeBSD/misc/

MAINTAINER=	kheuer@gwdg.de
COMMENT=	Remote printing utility using a raw bidirectional tcp connection

BROKEN=		unfetchable

LICENSE=	BSD4CLAUSE

PLIST_FILES=	bin/rprint man/man1/rprint.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s/^(CC|CFLAGS).+//g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rprint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/rprint.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

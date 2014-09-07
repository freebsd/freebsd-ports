# Created by: Marc Lagrange <rhaamo@gruik.at>
# $FreeBSD$

PORTNAME=	hwstat
PORTVERSION=	0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.rhaamo.li/Archives/hwstat/

MAINTAINER=	rhaamo@gruik.at
COMMENT=	Command line tool to display CPU temp and battery infos

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		uidfix
MAKE_ARGS+=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man
PLIST_FILES=	bin/hwstat man/man1/hwstat.1.gz

.include <bsd.port.mk>

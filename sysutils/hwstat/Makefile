PORTNAME=	hwstat
PORTVERSION=	0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/sysutils/hwstat/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Command line tool to display CPU temp and battery infos
WWW=		https://BSDforge.com/projects/sysutils/hwstat/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Unfetchable

USES=		uidfix
MAKE_ARGS+=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man
PLIST_FILES=	bin/hwstat man/man1/hwstat.1.gz

.include <bsd.port.mk>

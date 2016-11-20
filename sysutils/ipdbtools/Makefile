# $FreeBSD$

PORTNAME=	ipdbtools
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cyclaero.com/public/ipdbtools/

MAINTAINER=	cyclaero@gmail.com
COMMENT=	Tools for IP based Geo-blocking and Geo-routing

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2 compiler:c11

PLIST_FILES=	bin/ipup \
		bin/ipdb \
		bin/ipdb-update.sh \
		man/man1/ipdbtools.1.gz \
		man/man1/ipup.1.gz \
		man/man1/ipdb.1.gz \
		man/man1/ipdb-update.sh.1.gz

BROKEN_aarch64=		Fails to compile: error: invalid conversion between vector type and integer type
BROKEN_sparc64=		Fails to compile: error: unrecognized command line option -mssse3

.include <bsd.port.mk>

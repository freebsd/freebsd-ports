PORTNAME=	psdim
PORTVERSION=	1.4
PORTREVISION=	10
CATEGORIES=	print
MASTER_SITES=	http://www.mathstat.dal.ca/~selinger/psdim/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calculates the optimal placement of the pages for n-up printing
WWW=		https://www.mathstat.dal.ca/~selinger/psdim/

LICENSE=	GPLv2

USES=		ghostscript

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${PREFIX}/share/man

PLIST_FILES=	bin/psdim share/man/man1/psdim.1.gz

.include <bsd.port.mk>

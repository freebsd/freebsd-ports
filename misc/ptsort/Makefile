PORTNAME=	ptsort
PORTVERSION=	1.20170904
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/dag-erling/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	des@FreeBSD.org
COMMENT=	Prioritized topological sort
WWW=		https://github.com/dag-erling/ptsort

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>

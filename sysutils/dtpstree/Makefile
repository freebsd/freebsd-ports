PORTNAME=	dtpstree
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://dl1.douglasthrift.net/${PORTNAME}/ \
		http://dl2.douglasthrift.net/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Display a tree of processes
WWW=		https://code.douglasthrift.net/trac/dtpstree

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKEFILE=	GNUmakefile
USES=		gmake ncurses tar:xz

PLIST_FILES=	bin/dtpstree \
		share/man/man1/dtpstree.1.gz

.include <bsd.port.mk>

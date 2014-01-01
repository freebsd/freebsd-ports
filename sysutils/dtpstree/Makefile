# Created by: Douglas Thrift
# $FreeBSD$

PORTNAME=	dtpstree
PORTVERSION=	1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Display a tree of processes

LICENSE=	APACHE20

USE_XZ=		yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
USES=		gmake

MAN1=		dtpstree.1
PLIST_FILES=	bin/dtpstree \
		man/man1/dtpstree.1.gz

.include <bsd.port.mk>

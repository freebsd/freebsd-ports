# Created by: alfred@freebsd.org
# $FreeBSD$

PORTNAME=	hulgalugha
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/hulgalugha/
USE_BZIP2=	yes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very jerky text filter

PLIST_FILES=	bin/hulgalugha

post-patch:
	@${REINPLACE_CMD} -e "s/NOMAN/NO_MAN/" ${WRKSRC}/Makefile
.include <bsd.port.mk>

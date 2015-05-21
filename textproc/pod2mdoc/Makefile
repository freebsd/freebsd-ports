# $FreeBSD$

PORTNAME=	pod2mdoc
PORTVERSION=	0.2
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/pod2mdoc/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Convert POD data to mdoc input

LICENSE=	ISCL

USES=	tar:tgz
ALL_TARGET=	pod2mdoc

PLIST_FILES=	bin/pod2mdoc \
		man/man1/pod2mdoc.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s/OHASH=1/OHASH=0/g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pod2mdoc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pod2mdoc.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

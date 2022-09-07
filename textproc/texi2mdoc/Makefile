PORTNAME=	texi2mdoc
PORTVERSION=	0.1.2
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/texi2mdoc/snapshots/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Convert Texinfo data to mdoc input
WWW=		https://mdocml.bsd.lv/texi2mdoc/

LICENSE=	ISCL

USES=		tar:tgz

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

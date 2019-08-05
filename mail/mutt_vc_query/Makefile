# Created by: Oliver Braun
# $FreeBSD$

PORTNAME=	mutt_vc_query
PORTVERSION=	002
CATEGORIES=	mail
MASTER_SITES=	SF/rolo/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	vCard query utility for mutt

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	libvc>=003:devel/libvc

USES=		tar:bzip2
GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include \
		-L${PREFIX}/lib

PORTDOCS=	*
PLIST_FILES=	bin/mutt_vc_query man/man1/mutt_vc_query.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

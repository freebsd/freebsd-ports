# Created by: Oliver Braun
# $FreeBSD$

PORTNAME=	mutt_vc_query
PORTVERSION=	002
CATEGORIES=	mail
MASTER_SITES=	SF/rolo/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	vCard query utility for mutt

RUN_DEPENDS=	libvc>=003:${PORTSDIR}/devel/libvc
BUILD_DEPENDS:=	${RUN_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include \
		-L${PREFIX}/lib

PORTDOCS=	*
PLIST_FILES=	bin/mutt_vc_query man/man1/mutt_vc_query.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

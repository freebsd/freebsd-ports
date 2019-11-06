# Created by: itojun@itojun.org
# $FreeBSD$

PORTNAME=	rblcheck
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	moro@remus.dti.ne.jp
COMMENT=	Command-line interface to Paul Vixie's RBL filter

BROKEN=		unfetchable

USES=		gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rbl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/rblcheckrc.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

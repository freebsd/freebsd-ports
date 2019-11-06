# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	mod_layout
PORTVERSION=	5.1
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache2.2 module to wrap served pages with a header and/or footer

BROKEN=		unfetchable

CONFLICTS=	mod_layout-3.* mod_layout-4.*

PORTSCOUT=	limit:^5

USES=		apache:2.2+

MAKE_ARGS+=	builddir=${WRKSRC}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>

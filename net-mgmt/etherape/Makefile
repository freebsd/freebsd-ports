# Created by: Holger Lamm <holger@eit.uni-kl.de>
# $FreeBSD$

PORTNAME=	etherape
PORTVERSION=	0.9.13
PORTREVISION=	2
CATEGORIES=	net-mgmt gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical network traffic monitor tool modeled after Etherman

LICENSE=	GPLv2

USES=		gettext gmake iconv pathfix pkgconfig
USE_GNOME=	gnomedocutils libglade2 libgnomeui
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -export-dynamic	# XXX: G_MODULE_EXPORT?

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ README* TODO ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS
	${ICONV_CMD} -f latin1 -t utf-8 ${WRKSRC}/${f} > \
		${STAGEDIR}${DOCSDIR}/${f}
.endfor

.include <bsd.port.mk>

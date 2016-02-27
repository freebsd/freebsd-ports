# Created by: Kay Lehmann
# $FreeBSD$

PORTNAME=	lineakd
PORTVERSION=	0.9
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF/lineak/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	lineak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lineakd is a daemon which enables special keys on internet keyboards

USES=		gmake libtool localbase
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	kde_cv_prog_cxx_fno_check_new=no
INSTALL_TARGET=	install-strip

PORTDOCS=	README TODO AUTHORS
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/lineak/Makefile.in ${WRKSRC}/lineakd/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lineakd.conf.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

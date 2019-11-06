# Created by: fenner
# $FreeBSD$

PORTNAME=	xplot
PORTVERSION=	0.90.7.1
PORTREVISION=	3
CATEGORIES=	math graphics net
MASTER_SITES=	http://www.xplot.org/xplot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 plotting package

USES=		perl5 xorg
USE_XORG=	x11
USE_PERL5=	run
GNU_CONFIGURE=	yes

PORTDOCS=	README README.tcp_plots
PLIST_FILES=	bin/tcpdump2xplot bin/tcpdump2xplot.pl bin/xplot \
		man/man1/tcpdump2xplot.1.gz \
		man/man1/xplot.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/INSTALL/s|2xplot$$|2xplot.pl|' ${WRKSRC}/Makefile.in

post-install:
	${LN} -sf tcpdump2xplot.pl ${STAGEDIR}${PREFIX}/bin/tcpdump2xplot

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

# Created by: jeh@FreeBSD.org
# $FreeBSD$

PORTNAME=	mgstat
PORTVERSION=	0.12
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce graphs from mod_gzip log files

LIB_DEPENDS=	libgd.so:graphics/gd

GNU_CONFIGURE=	yes

PORTDOCS=	Copyright README USAGE
PLIST_FILES=	bin/mgstat

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

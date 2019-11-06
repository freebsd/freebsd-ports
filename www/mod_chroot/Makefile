# Created by: Alexey A.Ukhov <auk@startext.de>
# $FreeBSD$

PORTNAME=	mod_chroot
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://core.segfault.pl/~hobbit/mod_chroot/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	The mod_chroot makes running Apache in a chroot easy

BROKEN=		unfetchable

USES=		apache:2.2+ cpe
CPE_VENDOR=	marek_gutkowski
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	INSTALL CAVEATS README.Apache20 README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Andreas Fehlner <fehlner@gmx.de>
# $FreeBSD$

PORTNAME=	sn
PORTVERSION=	0.3.8
PORTREVISION=	3
CATEGORIES=	news
MASTER_SITES=	http://www.infa.abo.fi/~patrik/sn/files/ \
		http://home.arcor.de/teambushido/fbsd_ports/ \
		http://home.arcor.de/fehlner/fbsd_ports/

MAINTAINER=	fehlner@gmx.de
COMMENT=	Small news system for small sites serving

BROKEN=		unfetchable

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		gmake tar:bzip2
MAKE_ARGS+=	PREFIX="${PREFIX}" LD="${CC}" CC="${CC}"

PORTDOCS=	README CHANGES FAQ INSTALL INTERNALS \
		THANKS TODO INSTALL.notes INSTALL.notes2 \
		INSTALL.run INSTALL.upgrade

INSTALL_TARGET=	strip install

OPTIONS_DEFINE=	DOCS

# Try to fix parallel builds (-jX); respect CFLAGS
post-patch:
	${REINPLACE_CMD} -e 's|sn\.a$$|& lib/libstuff.a| ; \
		s|snlockf\.o$$|& lib/libstuff.a| ; \
		s|-g -Wall -pedantic -O|${CFLAGS} -Wall -pedantic| ; \
		s|strip |${STRIP_CMD} | ; \
		s|/bin/bash|${LOCALBASE}/bin/bash|' \
			${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}/var/spool/news
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

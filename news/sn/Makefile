# Created by: Andreas Fehlner <fehlner@gmx.de>
# $FreeBSD$

PORTNAME=	sn
PORTVERSION=	0.3.8
CATEGORIES=	news
MASTER_SITES=	http://www.infa.abo.fi/~patrik/sn/files/ \
		http://home.arcor.de/teambushido/fbsd_ports/\
		http://home.arcor.de/fehlner/fbsd_ports/

MAINTAINER=	fehlner@gmx.de
COMMENT=	Small news system for small sites serving

LICENSE=	GPLv2

USES=		gmake
USE_BZIP2=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}" LD="${CC}"

PORTDOCS=	README CHANGES FAQ INSTALL INTERNALS \
		THANKS TODO INSTALL.notes INSTALL.notes2 \
		INSTALL.run INSTALL.upgrade

MAN8=		sn.8 sncancel.8 sncat.8 sndelgroup.8 sndumpdb.8 \
		snexpire.8 snfetch.8 snget.8 sngetd.8 snmail.8 \
		snnewgroup.8 snntpd.8 snprimedb.8 snscan.8 snsend.8 \
		snsplit.8 snstore.8

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# Try to fix parallel builds (-jX); respect CFLAGS
post-patch:
	${REINPLACE_CMD} -e 's|sn\.a$$|& lib/libstuff.a| ; \
		s|snlockf\.o$$|& lib/libstuff.a| ; \
		s|-g -Wall -pedantic -O|${CFLAGS} -Wall -pedantic|' \
			${WRKSRC}/Makefile

pre-su-install:
	@${MKDIR} /var/spool/news

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

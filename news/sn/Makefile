# New ports collection makefile for:	sn
# Date created:		2004-02-21
# Whom:			Andreas Fehlner <fehlner@gmx.del>
#
# $FreeBSD$
#

PORTNAME=	sn
PORTVERSION=	0.3.8
CATEGORIES=	news
MASTER_SITES=	http://www.infa.abo.fi/~patrik/sn/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fehlner@gmx.de
COMMENT=	Small news system for small sites serving

PORTDOCS=	README CHANGES FAQ INSTALL INTERNALS \
		THANKS TODO INSTALL.notes INSTALL.notes2 \
		INSTALL.run INSTALL.upgrade

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN8=		sn.8 sncancel.8 sncat.8 sndelgroup.8 sndumpdb.8 \
		snexpire.8 snfetch.8 snget.8 sngetd.8 snmail.8 \
		snnewgroup.8 snntpd.8 snprimedb.8 snscan.8 snsend.8 \
		snsplit.8 snstore.8

post-patch:
	@${REINPLACE_CMD} -e 's|^PREFIX|#PREFIX|g' ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} /var/spool/news

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

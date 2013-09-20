# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squidview
PORTVERSION=	0.79
CATEGORIES=	www
MASTER_SITES=	http://www.rillion.net/squidview/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor squid statistics in realtime

GNU_CONFIGURE=	yes

MAN1=		squidview.1
DOCS=		HOWTO README
DATAFILES=	aliases users words

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squidview ${PREFIX}/bin/

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DATAFILES:S,^,${WRKSRC}/,} ${DATADIR}/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	${INSTALL_MAN} ${WRKSRC}/squidview.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>

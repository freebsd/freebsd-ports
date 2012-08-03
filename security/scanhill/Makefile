# New ports collection makefile for:	scanhill
# Date created:		2007-06-18
# Whom:			garga
#
# $FreeBSD$
#

PORTNAME=	scanhill
DISTVERSION=	0.5-p1
CATEGORIES=	security net-im
MASTER_SITES=	http://www.enderunix.org/scanhill/ \
		http://www.sourcefiles.org/Networking/Security/Sniffers/ \
		http://www.mirrorservice.org/sites/download.sourceforge.net/pub/sourceforge/s/sc/scanhill/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Microsoft Messenger Protocol Sniffer

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README.txt INSTALL.txt mysql.sql

OPTIONS_DEFINE=	MYSQL DOCS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=		yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanhill ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/scanhill.conf ${PREFIX}/etc/scanhill.conf-dist
.if !exists(${PREFIX}/etc/scanhill.conf)
	${INSTALL_DATA} ${WRKSRC}/scanhill.conf ${PREFIX}/etc/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>

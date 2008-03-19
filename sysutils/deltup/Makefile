# New ports collection makefile for:	deltup
# Date created:		2005-05-18
# Whom:			Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	deltup
PORTVERSION=	0.4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.deltup.org/e107_files/downloads/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Source delta update program

RUN_DEPENDS=	bdelta:${PORTSDIR}/misc/bdelta

USE_OPENSSL=	yes
USE_GMAKE=	yes

ALL_TARGET=	deltup
PLIST_FILES=	bin/deltup \
		bin/bzip2_old
MAN1=		deltup.1

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deltup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/deltup.1 ${PREFIX}/man/man1
.if !exists(${PREFIX}/bin/bzip2_old)
	@${LN} -s ${BZIP2_CMD} ${PREFIX}/bin/bzip2_old
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>

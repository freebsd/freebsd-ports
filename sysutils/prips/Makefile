# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	prips
PORTVERSION=	0.9.9
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/prips/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prints IP subnet ranges by list or CIDR

LICENSE=	GPLv2

PORTDOCS=	README
PLIST_FILES=	bin/prips

MAN1=		prips.1
MANCOMPRESSED=	yes

MAKE_ENV+=	CFLAGS_WARN="-Wall -W"

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prips ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/prips.1.gz ${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

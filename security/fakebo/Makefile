# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	fakebo
PORTVERSION=	0.4.2.1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fake BackOrifice client emulator

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing

MAN1=		fakebo.1
PORTDOCS=	README custom.replies
PLIST_FILES=	bin/fakebo etc/fakebo.conf.sample

post-extract:
	@${FIND} ${WRKSRC} -type l -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fakebo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fakebo.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/fakebo.conf.dist ${PREFIX}/etc/fakebo.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/custom.replies ${DOCSDIR}
.endif

.include <bsd.port.mk>

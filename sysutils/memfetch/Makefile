# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	memfetch
PORTVERSION=	0.05b
CATEGORIES=	sysutils
MASTER_SITES=	http://lcamtuf.coredump.cx/soft/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	Utility to dump process memory

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		perl5
USE_PERL5=	run

CFLAGS+=	${CPPFLAGS}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mffind.pl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

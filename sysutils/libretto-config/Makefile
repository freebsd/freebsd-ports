# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libretto-config
PORTVERSION=	1.0.b5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://club.pep.ne.jp/~ishioka/Software/Linux/libapm/
DISTNAME=	libapm-linux-1.0beta5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libretto BIOS Setting Program

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/libapm

PLIST_FILES=	sbin/libretto-config
MAN8=		${PORTNAME}.8
MANLANG=	. ja

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
# install japanese manpage also :-)
	${INSTALL_MAN} ${WRKSRC}/libapm-j.man ${PREFIX}/man/ja/man8/${PORTNAME}.8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-e.1st ${DOCSDIR}/README.1st
	${INSTALL_DATA} ${WRKSRC}/APM-EXBIOS-e.txt ${DOCSDIR}/APM-EXBIOS.txt
	@${MKDIR} ${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/README-j.1st ${DOCSDIR}/ja/README.1st
	${INSTALL_DATA} ${WRKSRC}/APM-EXBIOS-j.txt ${DOCSDIR}/ja/APM-EXBIOS.txt
.endif

.include <bsd.port.mk>

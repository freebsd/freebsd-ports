# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=		seatools
PORTVERSION=		2.54
CATEGORIES=		sysutils linux
MASTER_SITES=		${DOWNLOAD_URL}
PKGNAMEPREFIX=		linux-
DISTNAME=		seatools_cli
EXTRACT_SUFX=		.tar

MAINTAINER=		bsam@FreeBSD.org
COMMENT=		Seagate's SeaTools for Linux

DOWNLOAD_URL=		http://download.seagate.com/seatools/registration.nsf/linux_cli?openform
NO_WRKSUBDIR=		yes
RESTRICTED=		The distfile should be downloaded by hand
ONLY_FOR_ARCHS=		i386 amd64
USE_LINUX=		yes

PLIST_FILES=		sbin/st
PORTDOCS=		sthelp.txt

OPTIONS_DEFINE=		DOCS

NO_STAGE=	yes
do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/st

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/st ${PREFIX}/sbin/st
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sthelp.txt ${DOCSDIR}/sthelp.txt
.endif

.include <bsd.port.pre.mk>

.if (!exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
IGNORE=	please access ${DOWNLOAD_URL} with a web browser, fill the web form.\
Please place the downloaded ${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}
.endif

.include <bsd.port.post.mk>

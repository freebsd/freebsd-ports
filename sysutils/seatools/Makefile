# Ports collection makefile for:	linux-seatools
# Date created:		 		08 Apr 2007
# Whom:					Boris Samorodov <bsam@FreeBSD.org>
#
# $FreeBSD$
#

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

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/st

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/st ${PREFIX}/sbin/st

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/sthelp.txt ${DOCSDIR}/sthelp.txt
.endif

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
PLIST_SUB+=		PORTDOCS="@comment "
.else
PLIST_SUB+=		PORTDOCS=
.endif

.if (!exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Please access\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
with a web browser, fill the web form. Please place the downloaded\n\
${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}\n\n
.endif

.include <bsd.port.post.mk>

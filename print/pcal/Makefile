# New ports collection makefile for:  pcal
# Date created:               10 June 2001
# Whom:                       mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	pcal
PORTVERSION=	4.7.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript calendar program

DEPRECATED=	http://vuxml.FreeBSD.org/58fc2752-5f74-11d9-a9e7-0001020eed82.html
EXPIRATION_DATE=2005-02-13

USE_REINPLACE=	yes
MAKE_ENV=	CC="${CC}" HOST_CC="${CC}" PAPERSIZE="${PAPERSIZE}"
ALL_TARGET=	pcal

MAN1=		pcal.1
PLIST_FILES=	bin/pcal libexec/pcal.cgi
PORTDOCS=	ReadMe pcal.html pcalw.html

WWWSERVER!=	hostname

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|@@PREFIX@@|${PREFIX}|g' ${WRKSRC}/pcal.cgi
	@${REINPLACE_CMD} -e \
		's|@@WWWSERVER@@|${WWWSERVER}|g' ${WRKSRC}/pcal.html
	@${REINPLACE_CMD} -e \
		's|@@WWWSERVER@@|${WWWSERVER}|g' ${WRKSRC}/pcalw.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcal ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pcal.cgi ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/pcal.man ${MANPREFIX}/man/man1/pcal.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ReadMe ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pcal.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/pcalw.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

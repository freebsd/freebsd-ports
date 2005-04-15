# New ports collection makefile for:	apachepw
# Date Created:				07 April 2005
# Whom:					tundra
#
# $FreeBSD$
#

PORTNAME=	mkapachepw
PORTVERSION=	1.121
CATEGORIES=	www
MASTER_SITES=	http://www.tundraware.com/Software/mkapachepw/

MAINTAINER=	mkapachepw@tundraware.com
COMMENT=	A Group & Password Management Tool For Apache

USE_PYTHON=	yes

MANCOMPRESSED=	yes
MAN1=		mkapachepw.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in WHATSNEW.txt mkapachepw-license.txt mkapachepw.html mkapachepw.pdf mkapachepw.ps mkapachepw.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

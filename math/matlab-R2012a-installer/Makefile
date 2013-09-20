# Created by: Jason Bacon
# $FreeBSD$

PORTNAME=	matlab-R2012a-installer
PORTVERSION=	0.1
CATEGORIES=	math science java
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Mathworks(r) Matlab installation tool

USE_LINUX=	yes
USE_LINUX_APPS=	ncurses-base
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	linux
JAVA_RUN=	yes

NO_BUILD=	yes
SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>

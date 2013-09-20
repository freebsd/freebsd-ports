# Created by: kaworu
# $FreeBSD$

PORTNAME=	selenium
PORTVERSION=	0.6.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/17210

MAINTAINER=	kaworu@users.sourceforge.jp
COMMENT=	Selenium is web application test tool!

MAN1=		selenium.1
HAS_CONFIGURE=	yes

SUB_FILES=	pkg-message

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

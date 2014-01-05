# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	xstow
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Enhanced replacement for GNU stow written in C++

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

PLIST_FILES=	bin/merge-info bin/xstow \
		man/man1/merge-info.1.gz man/man1/xstow.1.gz \
		man/man5/xstow.ini.5.gz
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README TODO xstow.html xstow.ini xstow.ini.html

OPTIONS_DEFINE=	DOCS

post-install:
	(cd ${WRKSRC} && \
	 ${INSTALL_MAN} AUTHORS COPYING ChangeLog NEWS README TODO ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

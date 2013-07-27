# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paperkey
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://www.jabberwocky.com/software/paperkey/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Extract just the secret information out of OpenPGP secret keys

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/paperkey
MAN1=		paperkey.1
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# Setting ALL_TARGET to "all check" is racy and breaks parallel builds
post-build:
	${MAKE} -C ${BUILD_WRKSRC} check

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

.include <bsd.port.mk>

# Created by: Justin Stanford <jus@security.za.net>
# $FreeBSD$

PORTNAME=	ripmime
PORTVERSION=	1.4.0.10
CATEGORIES=	mail
MASTER_SITES=	http://www.pldaniels.com/ripmime/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Extracts attached files out of a MIME encoded email package

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/ripmime man/man1/ripmime.1.gz

pre-build:
	@${REINPLACE_CMD} -e 's!CC=!CC?=!; s!/usr/local!${PREFIX}!; \
		s!^CFLAGS=!CFLAGS ?=!' \
		${WRKSRC}/Makefile ${WRKSRC}/ripOLE/Makefile \
		${WRKSRC}/tnef/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/ripmime.1 ${STAGEDIR}${MANPREFIX}/man/man1/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

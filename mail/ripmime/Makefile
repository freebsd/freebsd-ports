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

USES=		manpages:install
PLIST_FILES=	bin/ripmime
MAN1=		ripmime.1

pre-build:
	@${REINPLACE_CMD} -e 's!CC=!CC?=!; s!/usr/local!${PREFIX}!; \
		s!^CFLAGS=!CFLAGS ?=!' \
		${WRKSRC}/Makefile ${WRKSRC}/ripOLE/Makefile \
		${WRKSRC}/tnef/Makefile

do-install:	install-all-manpages
	${INSTALL_PROGRAM} ${WRKSRC}/ripmime ${STAGEDIR}${PREFIX}/bin/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

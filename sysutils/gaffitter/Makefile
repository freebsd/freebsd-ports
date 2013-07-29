# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	gaffitter
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary packing utility that uses a genetic algorithm

LICENSE=	GPLv3 # or later

USE_BZIP2=	yes
USES=		gmake	# parallel builds (-jX) are broken with BSD make(1)

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

# Change "cd foo; $(MAKE)" into "$(MAKE) -C foo" to unbreak parallel builds
post-patch:
	@${REINPLACE_CMD} -E 's|cd (.+); (\$$\(MAKE\))|\2 -C \1|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

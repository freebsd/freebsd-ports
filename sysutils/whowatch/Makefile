# Created by: Daniel Harris <dannyboy@subdimension.com>
# $FreeBSD$

PORTNAME=	whowatch
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/IDS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays information in real time about users currently logged on

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/whowatch man/man1/${PORTNAME}.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${PATCHDIR}/utmpx-whowatch.h \
		${PATCHDIR}/utmpx-whowatch.c
.endif

pre-patch:
	@${FIND} ${WRKSRC} -name 'proc????.c' | ${XARGS} ${REINPLACE_CMD} -E \
		-e 's/kp_.?proc\.._/ki_/ ; s/pcred\.p_//'

.include <bsd.port.post.mk>

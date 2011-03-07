# New ports collection makefile for:   ddate
# Date created:		26 January 2005
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ddate
PORTVERSION=	2.19
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/v${PORTVERSION}/ \
		CRITICAL
DISTNAME=	util-linux-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command to print the date in Discordian date format

PLIST_FILES=	bin/ddate

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2

MAN1=		ddate.1

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may define the following build options:"
	@${ECHO} ""
	@${ECHO} "      US_FORMAT   if you wish to use the US format for"
	@${ECHO} "                  aneristic dates (m-d-y), as opposed to"
	@${ECHO} "                  the Commonwealth format"
	@${ECHO} ""
	@${ECHO} "      PRAISE_BOB  if you wish ddate to contain SubGenius"
	@${ECHO} "                  slogans"
	@${ECHO} ""
	@${ECHO} "      KILL_BOB    if you are ideologically, theologically or"
	@${ECHO} "                  otherwise opposed to the Church of the"
	@${ECHO} "                  SubGenius and do not wish your copy of"
	@${ECHO} "                  ddate to contain code for counting down"
	@${ECHO} "                  to X-Day"
	@${ECHO} ""
	@${ECHO} "      OLD_FORMAT  if you wish ddate to print the date in the"
	@${ECHO} "                  same format as Druel's original ddate when"
	@${ECHO} "                  called in immediate mode"
	@${ECHO} ""

post-patch:
.if defined(US_FORMAT)
	@${REINPLACE_CMD} -e 's/^\/\*\ \(#define\ US_FORMAT\)\ \*\//\1/' \
		${WRKSRC}/misc-utils/ddate.c
.endif
.if defined(PRAISE_BOB)
	@${REINPLACE_CMD} -e 's/^\/\*\(#define\ PRAISE_BOB\ 13013\)\*\//\1/' \
		${WRKSRC}/misc-utils/ddate.c
.endif
.if defined(KILL_BOB)
	@${REINPLACE_CMD} -e 's/^\(#define\ KILL_BOB\ 13013\)/\/* \1 *\//' \
		${WRKSRC}/misc-utils/ddate.c
.endif
.if !defined(OLD_FORMAT)
	@${REINPLACE_CMD} -e 's/^\(#define\ OLD_IMMEDIATE_FMT\)/\/* \1 *\//' \
		${WRKSRC}/misc-utils/ddate.c
.endif

do-build:
	${CC} ${WRKSRC}/misc-utils/ddate.c ${CFLAGS} \
		-o ${WRKSRC}/misc-utils/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} -m 0555 ${WRKSRC}/misc-utils/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/misc-utils/ddate.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>

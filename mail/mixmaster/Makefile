# Created by: Meyer Wolfsheim
# $FreeBSD$
#

PORTNAME=	mixmaster
PORTVERSION=	3.0.2d
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	http://www.c-s.li/ports/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mixmaster-update.pl.gz allpingers.txt.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Cryptographically secure anonymous remailer

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		perl5 ncurses

BUILD_WRKSRC=	${WRKSRC}/Mix/Src

PORTDOCS=	README HISTORY THANKS TODO
CONFIG_FILES=	abuse.txt.in dest.blk mix.cfg news.hlp pubring.mix type1.hlp \
		adminkey.txt end.hlp mix.cfg.ex pgp.hlp rab.blk usage.txt.in \
		blocked.txt.in header.blk mix.hlp pgponly.hlp reply.txt.in \
		dest.alw intro.hlp mlist.txt pubring.asc rlist.txt \
		allpingers.txt

OPTIONS_DEFINE=	DOCS

BROKEN_FreeBSD_9=	does not compile

post-patch:
	@${RM} ${WRKSRC}/Mix/conf/mix.cfg.orig
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|' ${WRKSRC}/Mix/Src/config.h \
		${WRKSRC}/Mix/Src/Makefile.in
	${CP} ${WRKSRC}/Mix/Src/Makefile.in ${WRKSRC}/Mix/Src/Makefile

pre-install:
	${GZCAT} ${DISTDIR}/mixmaster-update.pl.gz >${WRKDIR}/mixmaster-update.pl
	${GZCAT} ${DISTDIR}/allpingers.txt.gz >${WRKSRC}/Mix/conf/allpingers.txt
	${REINPLACE_CMD} -e "s|/etc/mixmaster|${ETCDIR}|g" ${WRKDIR}/mixmaster-update.pl
	${REINPLACE_CMD} -e "s|/usr/bin|${PREFIX}/bin|g" ${WRKDIR}/mixmaster-update.pl
	${MKDIR} ${STAGEDIR}${ETCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mix/Src/mixmaster ${STAGEDIR}${PREFIX}/bin/mixmaster
	${INSTALL_PROGRAM} ${WRKSRC}/Mix/Src/mpgp ${STAGEDIR}${PREFIX}/bin/mpgp
	${INSTALL_PROGRAM} ${WRKSRC}/Mix/Src/remailer ${STAGEDIR}${PREFIX}/bin/remailer
	${INSTALL_SCRIPT} ${WRKDIR}/mixmaster-update.pl ${STAGEDIR}${PREFIX}/bin/mixmaster-update
	${INSTALL_MAN} ${WRKSRC}/Mix/mixmaster.1 ${STAGEDIR}${PREFIX}/man/man1/mixmaster.1
	${INSTALL_MAN} ${WRKSRC}/Mix/mpgp.1 ${STAGEDIR}${PREFIX}/man/man1/mpgp.1
.for FILE in ${CONFIG_FILES}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/Mix/conf/${FILE} ${STAGEDIR}${ETCDIR}/${FILE}.sample
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/Mix/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

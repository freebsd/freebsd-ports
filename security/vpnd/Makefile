# New ports collection makefile for:	vpnd
# Date created:		25 March 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	vpnd
PORTVERSION=	1.1.0
CATEGORIES=	security
MASTER_SITES=	http://sunsite.dk/vpnd/archive/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes

DOCFILES=	README FAQ.TXT SPEED.TXT VERSIONS

post-patch:
	@${MV} ${WRKSRC}/Makefile.FreeBSD.in ${WRKSRC}/Makefile.FreeBSD.in_tmp
	@${SED} -e "s:^ETC_DIR=:ETC_DIR=	${PREFIX}/etc:" \
	< ${WRKSRC}/Makefile.FreeBSD.in_tmp > ${WRKSRC}/Makefile.FreeBSD.in

pre-configure:
	${REINPLACE_CMD} -e "s@-O3@${CFLAGS}@g; s@gcc@${CC}@g" \
		${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vpnd ${PREFIX}/sbin/vpnd
	@${INSTALL_DATA} ${WRKSRC}/vpnd.conf ${PREFIX}/etc/vpnd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/vpnd.chat ${PREFIX}/etc/vpnd.chat.sample
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "Make sure you set up a few IRQ's for random generation with rndcontrol before"
	@${ECHO} "trying to generate a master key file."
	@${ECHO} "================================================================================"

.include <bsd.port.mk>

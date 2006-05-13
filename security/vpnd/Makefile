# New ports collection makefile for:	vpnd
# Date created:		25 March 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	vpnd
PORTVERSION=	1.1.2
CATEGORIES=	security
MASTER_SITES=	http://vpnd.dotsrc.org/archive/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	VPN daemon offering transparent blowfish encryption between networks

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
USE_RC_SUBR=	yes

PLIST_FILES=	sbin/vpnd etc/rc.d/vpnd.sh etc/vpnd.conf.sample etc/vpnd.chat.sample
PORTDOCS=	README FAQ.TXT SPEED.TXT VERSIONS

post-patch:
.for f in README globals.c vpnd.c vpnd.conf
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e "s,machine/param.h,sys/param.h,g" ${WRKSRC}/vpnd.h
	@${REINPLACE_CMD} -e "s@-O3@${CFLAGS}@g; s@gcc@${CC}@g" ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vpnd ${PREFIX}/sbin/vpnd
	@${INSTALL_SCRIPT} ${FILESDIR}/vpnd.sh ${PREFIX}/etc/rc.d/vpnd.sh
	@${INSTALL_DATA} ${WRKSRC}/vpnd.conf ${PREFIX}/etc/vpnd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/vpnd.chat ${PREFIX}/etc/vpnd.chat.sample
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

post-install:
.if ${OSVERSION} < 500000
	@${ECHO} "================================================================================"
	@${ECHO} "Make sure you set up a few IRQ's for random generation with rndcontrol before"
	@${ECHO} "trying to generate a master key file."
	@${ECHO} "================================================================================"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	spreadlogd
# Date created:			08 May 2005
# Whom:				Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	spreadlogd
PORTVERSION=	1.4.2
CATEGORIES=	www net
MASTER_SITES=	http://www.lethargy.org/mod_log_spread/

MAINTAINER=	meno.abels@adviser.com
COMMENT=	The backend of mod_log_spread

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread

MAKEFILE=	makefile

USE_RC_SUBR=	spreadlogd.sh
SUB_FILES=	spreadlogd.sh

PLIST_FILES=	sbin/spreadlogd etc/spreadlogd.conf.sample

.if !defined(NOPORTDOCS)
PORTDOCS=	README Artistic.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/spreadlogd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spreadlogd ${PREFIX}/sbin
	${INSTALL} ${WRKSRC}/spreadlogd.conf ${PREFIX}/etc/spreadlogd.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

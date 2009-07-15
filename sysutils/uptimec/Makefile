# New ports collection makefile for:	uptimec
# Date created:		5 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	uptimec
PORTVERSION=	0.2p5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mrEriksson.net/downloads/ \
		ftp://ftp.mrEriksson.net/pub/uptimec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client for Uptime Project

USE_RC_SUBR=	${PORTNAME}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/uptimec etc/uptimecrc.sample
PORTDOCS=	README ChangeLog INSTALL protocol.txt

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uptimec ${PREFIX}/sbin
	${INSTALL_DATA} ${FILESDIR}/uptimecrc.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>

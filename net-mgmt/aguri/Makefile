# New ports collection makefile for:    aguri
# Date created:                        	27 February 2003
# Whom: 				Yann Berthier <yb@sainte-barbe.org>
#
# $FreeBSD$
#

PORTNAME=	aguri
PORTVERSION=	0.7
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	yb@bashibuzuk.net
COMMENT=	An Aggregation-based Traffic Profiler

.if defined(WITH_X11)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile
USE_XLIB=	yes
.endif

MAN1=		aguri.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/aguri ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/aguri.1 ${MANPREFIX}/man/man1

post-install:

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILES in CHANGES INSTALL README
	@${INSTALL_DATA} ${WRKSRC}/${FILES} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/scripts/README ${DATADIR}
.for SCRIPTS in agurify.pl density.pl makeimages.pl makeplot.pl
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/${SCRIPTS} \
	${DATADIR}
.endfor

.include <bsd.port.mk>

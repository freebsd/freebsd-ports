# New ports collection makefile for:	tkman
# Version required:     2.1b1
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.31 1998/07/30 11:48:55 tg Exp $
#

DISTNAME=	tkman-2.1b1
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11-toolkits/tk80
RUN_DEPENDS=	rman:${PORTSDIR}/textproc/rman \
		glimpse:${PORTSDIR}/textproc/glimpse

NO_CDROM=	"License required"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/tkman
	${INSTALL_DATA} ${WRKSRC}/tkman-help.html ${PREFIX}/share/doc/tkman
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	tkman
# Version required:     2.0.5
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.28 1997/12/08 15:51:20 tg Exp $
#

DISTNAME=	tkman-2.0.5
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	tk80\\.1\\.:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	rman:${PORTSDIR}/textproc/rman \
		glimpse:${PORTSDIR}/textproc/glimpse

NO_CDROM=	"License required"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/tkman
	${INSTALL_DATA} ${WRKSRC}/tkman-help.html ${PREFIX}/share/doc/tkman
.endif

.include <bsd.port.mk>

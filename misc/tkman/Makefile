# New ports collection makefile for:	tkman
# Version required:     2.1b2
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	tkman-2.1b2
CATEGORIES=	misc tk82
MASTER_SITES=	ftp://ftp.cs.berkeley.edu/ucb/people/phelps/tcltk/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
RUN_DEPENDS=	rman:${PORTSDIR}/textproc/rman \
		glimpse:${PORTSDIR}/textproc/glimpse

NO_CDROM=	"License required"

post-patch:
	perl -pi -e "s;/usr/local/bin/wish;${PREFIX}/bin/wish8.2;" \
		${WRKSRC}/contrib/tkmanclient

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tkman
	${INSTALL_DATA} ${WRKSRC}/tkman-help.html ${PREFIX}/share/doc/tkman
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/tkmanclient ${PREFIX}/bin

.include <bsd.port.mk>

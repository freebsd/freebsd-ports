# New ports collection makefile for:	tkman
# Date created:         27 Dec 1994
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkman
PORTVERSION=	2.1
CATEGORIES=	misc tk83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	rman:${PORTSDIR}/textproc/rman \
		glimpse:${PORTSDIR}/textproc/glimpse

post-patch:
	${PERL} -pi -e "s;/usr/local/bin/wish;${LOCALBASE}/bin/wish8.3;" \
		${WRKSRC}/contrib/tkmanclient

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tkman
	${INSTALL_DATA} ${WRKSRC}/tkman-help.html ${PREFIX}/share/doc/tkman
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/tkmanclient ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${FILESDIR}/310.index_manpages ${PREFIX}/etc/periodic/weekly

.include <bsd.port.mk>

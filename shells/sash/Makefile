# New ports collection makefile for:	sash
# Date created:		Jan 22, 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sash
PORTVERSION=	3.7
CATEGORIES=	shells
MASTER_SITES=	http://www.canb.auug.org.au/%SUBDIR%/
MASTER_SITE_SUBDIR=	~dbell/programs

MAINTAINER=	ports@freebsd.org
COMMENT=	A Stand-Alone shell combining many common utilities

MAN1=		sash.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sash ${PREFIX}/bin/sash
	${INSTALL_MAN} ${WRKSRC}/sash.1 ${MAN1PREFIX}/man/man1/sash.1
	@${ECHO_MSG} "------------------"
	@${ECHO_MSG} "Installing into ${PREFIX}/bin"
	@${ECHO_MSG} "If you want this installed elsewhere, "
	@${ECHO_MSG} "set the environmental variable PREFIX"
	@${ECHO_MSG} "------------------"

post-install:
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/sash /etc/shells.bak; \
		${ECHO_CMD} ${PREFIX}/bin/sash) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>

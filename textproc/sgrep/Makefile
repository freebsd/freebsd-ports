# Created by: <koshy@india.hp.com>
# $FreeBSD$

PORTNAME=	sgrep
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.helsinki.fi/pub/Software/Local/Sgrep/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A `grep' for structured text like SGML and HTML

CONFLICTS=	sgrep2-1.*

MAN1=		sgrep.1

# Override the install target in the supplied makefile
NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sgrep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sgrep.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/sample.sgreprc ${PREFIX}/share/sgreprc

.include <bsd.port.mk>

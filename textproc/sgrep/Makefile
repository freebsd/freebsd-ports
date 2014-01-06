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
COMMENT=	Grep for structured text like SGML and HTML

CONFLICTS=	sgrep2-1.*

# Override the install target in the supplied makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sgrep ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sgrep.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/sample.sgreprc ${STAGEDIR}${PREFIX}/share/sgreprc

.include <bsd.port.mk>

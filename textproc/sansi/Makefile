# Created by: Chris Hutchinson <portmaster@bsdforge.com>
# $FreeBSD$

PORTNAME=	sansi
PORTVERSION=	1.0.2
CATEGORIES=	textproc sysutils
MASTER_SITES=	https://BSDforge.com/projects/source/textproc/sansi/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Removes ANSI control sequences/characters, from files

LICENSE=	ART20 BSD2CLAUSE
LICENSE_COMB=	multi

RUN_DEPENDS=	p5-PerlIO-eol>=0:devel/p5-PerlIO-eol \
		p5-Modern-Perl>=0:lang/p5-Modern-Perl

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		tar:xz

PLIST_FILES=	sbin/sansi man/man1/sansi.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sansi ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/sansi.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

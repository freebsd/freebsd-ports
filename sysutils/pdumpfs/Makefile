# Ports collection makefile for:	pdumpfs
# Date created:			30 April 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pdumpfs
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://namazu.org/~satoru/pdumpfs/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A daily backup system similar to Plan9's dumpfs

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/pdumpfs.in
ALL_TARGET=	pdumpfs
DOCS=		ChangeLog README doc/*

MANLANG=	"" ja
MAN8=		pdumpfs.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdumpfs ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/man8/pdumpfs.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/ja/man8/pdumpfs.8 ${PREFIX}/man/ja/man8/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>

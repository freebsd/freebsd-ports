# Ports collection makefile for:	clex-tty
# Date created:				Tue Oct 30, 2002
# Whom:			Michael L. Hostbaek <mich@freebsdcluster.org>
#
# $FreeBSD$
#

PORTNAME=	clex
PORTVERSION=	3.17
CATEGORIES=	misc
MASTER_SITES=	http://www.clex.sk/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A commandline file manager

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README
MAN1=		clex.1

OPTIONS=	LARGE_FILES "Enable support for large files" on

.include <bsd.port.pre.mk>

.if !defined(WITH_LARGE_FILES)
CONFIGURE_ARGS+=	--disable-largefile
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${INSTALL_MAN} ${WRKSRC}/src/${MAN1} ${MAN1PREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>

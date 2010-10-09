# New ports collection makefile for:   parallel
# Date created:        22 September 2010
# Whom:                Chris Howey <howeyc@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	parallel
PORTVERSION=	20100922
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	howeyc@gmail.com
COMMENT=	GNU parallel is a shell tool for executing jobs in parallel

CONFLICTS=	moreutils-[0-9]*

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir="${PREFIX}"\
				--docdir="${PREFIX}/share/doc/${PORTNAME}"

MAN1=	parallel.1 sem.1 sql.1
MANCOMPRESSED=	no
USE_BZIP2=	yes
USE_PERL5=	yes

PORTDOCS=	parallel.html sem.html sql.html

PLIST_FILES=	bin/parallel \
	bin/sem \
	bin/sql

.include <bsd.port.mk>

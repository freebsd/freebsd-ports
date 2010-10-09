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

CONFIGURE_ARGS=	--docdir="${DOCSDIR}"
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes

MAN1=		parallel.1 sem.1 sql.1
PLIST_FILES=	bin/parallel bin/sem bin/sql
PORTDOCS=	parallel.html sem.html sql.html

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-docDATA||' ${WRKSRC}/src/Makefile.in
.endif

.include <bsd.port.mk>

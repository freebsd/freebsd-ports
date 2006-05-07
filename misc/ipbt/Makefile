# New ports collection makefile for:   ipbt
# Date created:                7 May 2006
# Whom:                        Matt Mills <matt_mills@btopenworld.com>
#
# $FreeBSD$
#

PORTNAME=	ipbt
DISTVERSION=	r6489
CATEGORIES=	misc
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/ipbt/

MAINTAINER=	matt_mills@btopenworld.com
COMMENT=	A high-tech ttyrec player with improvements over ttyplay

USE_PERL5_BUILD=	yes

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/ipbt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		requires mbrtowc() and wcrtomb()
.endif

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL} -w|' ${WRKSRC}/sbcsgen.pl
	@${REINPLACE_CMD} -e 's|perl|${PERL}|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>

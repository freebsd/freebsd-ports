# New ports collection makefile for:	boa
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	boa
PORTVERSION=	0.94.8.3
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN8=		boa.8

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/defines.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/boa ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/../docs/boa.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/../boa.conf ${PREFIX}/etc/boa.conf.sample
	@${MKDIR} ${PREFIX}/share/examples/boa
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${PREFIX}/share/examples/boa
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/boa
	${INSTALL_DATA} ${WRKSRC}/../docs/boa.sgml ${PREFIX}/share/doc/boa
	${INSTALL_DATA} ${WRKSRC}/../docs/boa_banner.png ${PREFIX}/share/doc/boa
.endif

.include <bsd.port.mk>

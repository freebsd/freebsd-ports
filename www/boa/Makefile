# New ports collection makefile for:	boa
# Date created:				21 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	boa
PORTVERSION= 	0.94.6
CATEGORIES=	www
MASTER_SITES=	http://www.boa.org/

MAINTAINER=	ports@FreeBSD.org

FETCH_BEFORE_ARGS=	-b

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

BOA_DOCS=	boa-1.html boa-2.html boa-3.html boa-4.html boa.html \
		boa.ps boa.txt boa_banner.png

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/defines.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/boa ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/../boa.conf ${PREFIX}/etc/boa.conf.sample
	@${MKDIR} ${PREFIX}/share/examples/boa
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${PREFIX}/share/examples/boa
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/boa
.for file in ${BOA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/../docs/${file} ${PREFIX}/share/doc/boa
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:   webstone
# Date created:        25 March 1997
# Whom:                Soren Dossing <sauber@netcom.com>
#
# $FreeBSD$
#

PORTNAME=	webstone
PORTVERSION= 	2.0.1
CATEGORIES=	www benchmarks
#WebStone no longer distributed by SGi
#MASTER_SITES=	http://www.sgi.com/Products/WebFORCE/WebStone/
DISTNAME=	WebStone-2.0

MAINTAINER=	sauber@netcom.com

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/WebStone/src
ALL_TARGET=	install
NO_INSTALL_MANPAGES=	yes

post-extract:
	( cd ${WRKSRC}; make clobber )

# otherwise these files will be installed by do-install target below
post-patch:
	find ${WRKSRC}/.. -name '*.orig' | xargs rm -f

do-install:
	@${MKDIR} ${PREFIX}/webstone/bin
	@${MKDIR} ${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${PREFIX}/webstone/bin
	${INSTALL_DATA} ${WRKSRC}/../conf/* ${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../webstone  ${PREFIX}/webstone
.for file in webclient webmaster genrand
	strip ${PREFIX}/webstone/bin/${file}
.endfor

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

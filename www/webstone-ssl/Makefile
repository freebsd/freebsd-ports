# Created by: Kazumasa Nishizawa <k_nishizawa@anet.ne.jp>
# $FreeBSD$

PORTNAME=	webstone
PORTVERSION=	2.5
CATEGORIES=	www benchmarks
MASTER_SITES=	http://crypto.stanford.edu/~nagendra/projects/WebStone/download/
PKGNAMESUFFIX=	-ssl
DISTNAME=	WebStone-SSL-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	World wide web server benchmarking with SSL support

USE_OPENSSL=	yes
USE_AUTOTOOLS=	autoconf213
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/WebStone${PORTVERSION}/src
ALL_TARGET=	install
NO_INSTALL_MANPAGES=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ENV=	LIBS=-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

do-install:
	@${RMDIR} ${WRKSRC}/../bin/runs
	@${MKDIR} ${PREFIX}/webstone-ssl/bin
	@${MKDIR} ${PREFIX}/webstone-ssl/conf
	@${MKDIR} ${PREFIX}/webstone-ssl/lgm
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${PREFIX}/webstone-ssl/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../lgm/* ${PREFIX}/webstone-ssl/lgm
	${INSTALL_DATA} ${WRKSRC}/../conf/* ${PREFIX}/webstone-ssl/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../webstone  ${PREFIX}/webstone-ssl
	@${MKDIR} ${WRKSRC}/../bin/runs
.for file in webclient webmaster genrand
	${STRIP_CMD} ${PREFIX}/webstone-ssl/bin/${file}
.endfor
.for file in ws20_cgi ws25_cgi
	${STRIP_CMD} ${PREFIX}/webstone-ssl/lgm/${file}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:   bsmtp
# Date created:                2000-10-05
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	bsmtp
PORTVERSION=	1.02
CATEGORIES=	mail
MASTER_SITES=	http://www.stud.uni-karlsruhe.de/~uk1o/bsmtp/

MAINTAINER=	naddy@mips.inka.de

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--redo

pre-configure:
	@${SED} <${FILESDIR}/config.sed >${WRKSRC}/config.sed \
		-e 's:%%CC%%:${CC}:' \
		-e 's:%%CFLAGS%%:${CFLAGS}:' \
		-e 's:%%PREFIX%%:${PREFIX}:'

post-install:
	${MKDIR} ${PREFIX}/share/doc/bsmtp
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bsmtp/

.include <bsd.port.mk>

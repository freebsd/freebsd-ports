# Created by: Matt Mills <matt_mills@btopenworld.com>
# $FreeBSD$

PORTNAME=	ipbt
DISTVERSION=	r8765
CATEGORIES=	misc
MASTER_SITES=	http://www.chiark.greenend.org.uk/~sgtatham/ipbt/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	A high-tech ttyrec player with improvements over ttyplay

MAN1=		ipbt.1

USES=		perl5

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/ipbt bin/ttygrep bin/ttydump

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL} -w|' ${WRKSRC}/sbcsgen.pl
	@${REINPLACE_CMD} -e 's|perl|${PERL}|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ttydump ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ttygrep ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipbt.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

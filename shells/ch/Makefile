PORTNAME=	ch
PORTVERSION=	7.0.0
PORTREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	http://www.softintegration.com/download/software/release/FreeBSD/
DISTNAME=	chstandard-${PORTVERSION}.freebsd9.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeddable C/C++ interpreter/shell

IA32_BINARY_PORT=	yes
NO_BUILD=	yes
MANDIRS=	${DATADIR}/docs/man/

DATADIR=	${PREFIX}/${PORTNAME}

SUB_FILES=	${PORTNAME}
PORTDATA=	README  bin config demos dl extern include lib license package sbin toolkit

post-extract:
	@${MKDIR} ${WRKSRC}/ch
	@${TAR} zxf ${WRKSRC}/ch.bin -C ${WRKSRC}/ch

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/ch && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
